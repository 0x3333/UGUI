// Based on Fork: https://github.com/MarioIvancic/UGUI/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

#include "simulation.h"
#include "ugui.h"

#define WIDTH               320
#define HEIGHT              100
#define SCREEN_MULTIPLIER   2
#define SCREEN_MARGIN       15
#define WINDOW_BACK_COLOR   0x00C0C0C0

//Internal function declarations
void x11_pset(UG_S16 x, UG_S16 y, UG_COLOR c);
void x11_flush(void);
bool x11_setup(int width, int height);
void x11_process();

int main (void)
{
    printf("Simulation Application\n");

    //Setup X
    if (true != x11_setup(WIDTH, HEIGHT))
    {
        printf("Error Initializing X11 driver\n");
        return 0;
    }
    //Setup UGUI
    GUI_Setup(&x11_pset, &x11_flush, WIDTH, HEIGHT);

    while (true)
    {
        GUI_Process();
        x11_process();
        usleep(100000);
    }
    return 0;
}

//Data Defines
typedef struct x11_data_s
{
    Display *dis;
    Window win;
    GC gc;
    Visual *visual;
    int screen;
    uint32_t *imgBuffer;
    int simX;
    int simY;
} x11_data_t;

//Global Vars -- I hate these too
x11_data_t *handle;

bool x11_setup(int width, int height)
{
    //Mem Alloc's
    handle = (x11_data_t *)malloc(sizeof(x11_data_t));
    if (NULL == handle)
        return false;

    handle->imgBuffer = (UG_U32 *)malloc(width * SCREEN_MULTIPLIER * height * SCREEN_MULTIPLIER * sizeof(UG_U32));
    if (NULL == handle->imgBuffer)
        return false;
    handle->simX = width;
    handle->simY = height;

    //Setup X
    unsigned long black,white;

    handle->dis = XOpenDisplay((char *)0);
    handle->screen = DefaultScreen(handle->dis);
    black = BlackPixel(handle->dis, handle->screen),
    white = WhitePixel(handle->dis, handle->screen);
    handle->win = XCreateSimpleWindow(handle->dis,
                                  DefaultRootWindow(handle->dis),
                                  0,
                                  0,
                                  width * SCREEN_MULTIPLIER + (SCREEN_MARGIN * 2),
                                  height * SCREEN_MULTIPLIER + (SCREEN_MARGIN * 2),
                                  5,
                                  black,
                                  WINDOW_BACK_COLOR);
    XSetStandardProperties(handle->dis, handle->win, "uGUI Window",
                         "uGUI", None, NULL, 0, NULL);
    XSelectInput(handle->dis, handle->win,
               ExposureMask|ButtonPressMask|
               ButtonReleaseMask|KeyPressMask|Button1MotionMask);
    handle->gc = XCreateGC(handle->dis, handle->win, 0,0);
    XSetBackground(handle->dis, handle->gc, white);
    XSetForeground(handle->dis, handle->gc, black);
    XClearWindow(handle->dis, handle->win);
    XMapRaised(handle->dis, handle->win);
    handle->visual = DefaultVisual(handle->dis, 0);

    return true;
}

// http://www.mi.uni-koeln.de/c/mirror/www.cs.curtin.edu.au/units/cg252-502/notes/lect5h1.html

//Process Function
void x11_process(void)
{
    XEvent event;
    uint32_t *ximage = (uint32_t *)malloc(handle->simX * handle->simY * sizeof(UG_U32));

    //Check for events
    while (XCheckMaskEvent(handle->dis,
        ButtonPressMask | ButtonReleaseMask | Button1MotionMask | PointerMotionMask, &event) == true)
    {
        #if defined(UGUI_USE_TOUCH)
        static int mouse_down;
        switch (event.type)
        {
            case ButtonPress:
                // we are interested only in LEFT button (button 1)
                if(event.xbutton.button != 1)
                    break;
                mouse_down = 1;
                UG_TouchUpdate((event.xbutton.x - SCREEN_MARGIN) / SCREEN_MULTIPLIER, (event.xbutton.y - SCREEN_MARGIN) / SCREEN_MULTIPLIER, TOUCH_STATE_PRESSED);
            break;

            case ButtonRelease:
                // we are interested only in LEFT button (button 1)
                if(event.xbutton.button != 1)
                    break;
                mouse_down = 0;
                UG_TouchUpdate(-1, -1, TOUCH_STATE_RELEASED);
            break;

            case MotionNotify:
                if(mouse_down && ( event.xmotion.state & Button1Mask ))
                {
                    UG_TouchUpdate((event.xmotion.x - SCREEN_MARGIN) / SCREEN_MULTIPLIER, (event.xmotion.y - SCREEN_MARGIN) / SCREEN_MULTIPLIER, TOUCH_STATE_PRESSED);
                }
            break;
        }
        #endif
    }

    if (ximage != NULL)
    {
        memcpy(ximage, handle->imgBuffer, handle->simX * SCREEN_MULTIPLIER * handle->simY * SCREEN_MULTIPLIER * sizeof(UG_U32));
        XImage *img = XCreateImage(handle->dis,
                                   handle->visual,
                                   24,
                                   ZPixmap,
                                   0,
                                   (char *)ximage,
                                   handle->simX * SCREEN_MULTIPLIER,
                                   handle->simY * SCREEN_MULTIPLIER,
                                   32,
                                   0);
        XPutImage(handle->dis,
              handle->win,
              handle->gc,
              img,
              0,
              0,
              SCREEN_MARGIN,
              SCREEN_MARGIN,
              handle->simX * SCREEN_MULTIPLIER,
              handle->simY * SCREEN_MULTIPLIER);
        XDestroyImage(img);
        XFlush(handle->dis);
    }
}

//Internal
void x11_pset(UG_S16 x, UG_S16 y, UG_COLOR c)
{
    UG_U32 tmp = c;

/* Convert B/W to RGB888 */
#if defined(UGUI_USE_COLOR_BW)
    tmp = c == C_WHITE ? 0xFFFFFF : 0x000000;

/* Convert RGB565 to RGB888 */
#elif defined(UGUI_USE_COLOR_RGB565)
    UG_U8 r,g,b;
    r = (tmp>>11)&0x1F;
    r<<=3;
    g = (tmp>>5)&0x3F;
    g<<=2;
    b = (tmp)&0x1F;
    b<<=3;
    tmp = ((UG_U32)r<<16) | ((UG_U32)g<<8) | (UG_U32)b;
#endif

    for(UG_U8 i = 0; i < SCREEN_MULTIPLIER ; i++) {
        for(UG_U8 j = 0; j < SCREEN_MULTIPLIER ; j++) {
            handle->imgBuffer[(WIDTH * SCREEN_MULTIPLIER * ((y * SCREEN_MULTIPLIER) + j)) + (x * SCREEN_MULTIPLIER) + i] = tmp;
        }
    }
}

void x11_flush(void)
{
    // nop
}

static const char* message_type[] = { "NONE", "WINDOW", "OBJECT" };
static const char* event_type[] = {
    "NONE",
    "CLICKED",
    "PRERENDER",
    "POSTRENDER",
    "PRESSED",
    "RELEASED"
    };

void decode_msg(UG_MESSAGE* msg)
{
    printf("%s %s for ID %d (SubId %d)\n", 
        message_type[msg->type],
        event_type[msg->event],
        msg->id, msg->sub_id);
}
