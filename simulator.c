#include <stdlib.h>
#include <stdio.h>

#include "ugui.h"
#include "ugui_button.h"
#include "ugui_checkbox.h"
#include "ugui_textbox.h"
#include "ugui_image.h"
#include "simulation.h"

//Global Vars
#define MAX_OBJS 5
UG_GUI ugui;
UG_WINDOW wnd;
UG_BUTTON btn;
UG_CHECKBOX chb;
UG_TEXTBOX txt;
UG_OBJECT objs[MAX_OBJS];

// Internal Functions
void windowHandler(UG_MESSAGE *msg);
extern void decode_msg(UG_MESSAGE* msg);

void GUI_Setup(void *pset, void *flush, int w, int h)
{
    //Setup UGUI
    UG_Init(&ugui, pset, flush, w, h);

    UG_FillScreen(C_BLACK);

    //Setup Window
    UG_WindowCreate(&wnd, objs, MAX_OBJS, &windowHandler);
    UG_WindowSetTitleTextFont (&wnd, &FONT_6X8);
    UG_WindowSetTitleText(&wnd, "App Title");

    UG_ButtonCreate(&wnd, &btn, BTN_ID_0, UGUI_POS(3, 3, 40, 30));
    UG_ButtonSetFont(&wnd, BTN_ID_0, &FONT_6X8);
    UG_ButtonSetText(&wnd, BTN_ID_0, "BTN");
    UG_ButtonShow(&wnd, BTN_ID_0);

    UG_CheckboxCreate(&wnd, &chb, CHB_ID_0, UGUI_POS(46, 3, 40, 12));
    UG_CheckboxSetFont(&wnd, CHB_ID_0, &FONT_6X8);
    UG_CheckboxSetText(&wnd, CHB_ID_0, "CHB");
    UG_CheckboxSetAlignment(&wnd, CHB_ID_0, ALIGN_CENTER_LEFT);
    UG_CheckboxShow(&wnd, CHB_ID_0);

    UG_TextboxCreate(&wnd, &txt, TXB_ID_0, UGUI_POS(89, 3, 100, 30));
    UG_TextboxSetFont(&wnd, TXB_ID_0, &FONT_16X26);
    UG_TextboxSetText(&wnd, TXB_ID_0, "TXT");
    UG_TextboxShow(&wnd, TXB_ID_0);

    UG_WindowShow(&wnd);
}

void GUI_Process()
{
    UG_Update();
}

void windowHandler(UG_MESSAGE *msg)
{
    static UG_U16 x0, y0;

    decode_msg(msg);

    #if defined(UGUI_USE_TOUCH)
    if((msg->event == OBJ_EVENT_CLICKED) && (msg->type == MSG_TYPE_OBJECT))
    {
        //UG_OBJECT* obj = UG_FindObject(&wnd, msg->sub_id);
        UG_OBJECT* obj = *(UG_OBJECT**) msg->src;
        if(obj)
        {
            if(obj->touch_state & OBJ_TOUCH_STATE_CHANGED)                  printf("|CHANGED");
            if(obj->touch_state & OBJ_TOUCH_STATE_PRESSED_ON_OBJECT)        printf("|PRESSED_ON_OBJECT");
            if(obj->touch_state & OBJ_TOUCH_STATE_PRESSED_OUTSIDE_OBJECT)   printf("|PRESSED_OUTSIDE_OBJECT");
            if(obj->touch_state & OBJ_TOUCH_STATE_RELEASED_ON_OBJECT)       printf("|RELEASED_ON_OBJECT");
            if(obj->touch_state & OBJ_TOUCH_STATE_RELEASED_OUTSIDE_OBJECT)  printf("|RELEASED_OUTSIDE_OBJECT");
            if(obj->touch_state & OBJ_TOUCH_STATE_IS_PRESSED_ON_OBJECT)     printf("|IS_PRESSED_ON_OBJECT");
            if(obj->touch_state & OBJ_TOUCH_STATE_IS_PRESSED)               printf("|IS_PRESSED");
            if(obj->touch_state & OBJ_TOUCH_STATE_CLICK_ON_OBJECT)          printf("|CLICK_ON_OBJECT");
            if(obj->touch_state & OBJ_TOUCH_STATE_INIT)                     printf("|INIT");
            printf("\n");
            if( obj->touch_state & OBJ_TOUCH_STATE_IS_PRESSED )
            {
                x0 = ugui.touch.xp;
                y0 = ugui.touch.yp;
            }
        }
    }
    #endif
}
