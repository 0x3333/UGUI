#ifndef __UGUI_THEME_DEFAULT_H
#define __UGUI_THEME_DEFAULT_H

#include "ugui_colors.h"

#if defined(UGUI_USE_COLOR_RGB888)

#if !defined(C_DESKTOP_COLOR)
#define C_DESKTOP_COLOR              0x5E8BEF
#endif
#if !defined(C_FORE_COLOR)
#define C_FORE_COLOR                 C_BLACK
#endif
#if !defined(C_BACK_COLOR)
#define C_BACK_COLOR                 0xF0F0F0
#endif
#if !defined(C_TITLE_FORE_COLOR)
#define C_TITLE_FORE_COLOR    C_WHITE
#endif
#if !defined(C_TITLE_BACK_COLOR)
#define C_TITLE_BACK_COLOR    C_BLUE
#endif
#if !defined(C_INACTIVE_TITLE_FORE_COLOR)
#define C_INACTIVE_TITLE_FORE_COLOR    C_WHITE
#endif
#if !defined(C_INACTIVE_TITLE_BACK_COLOR)
#define C_INACTIVE_TITLE_BACK_COLOR    C_GRAY
#endif

const UG_COLOR pal_window[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE_41,
    C_WHITE_41,
    /* Frame 2 */
    C_WHITE_89,
    C_WHITE_89,
    C_WHITE_63,
    C_WHITE_63
};

const UG_COLOR pal_button_pressed[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    /* Frame 2 */
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94
};

const UG_COLOR pal_button_released[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE_41,
    C_WHITE_41,
    /* Frame 2 */
    C_WHITE_89,
    C_WHITE_89,
    C_WHITE_63,
    C_WHITE_63
};

const UG_COLOR pal_checkbox_pressed[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    /* Frame 2 */
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94
};

const UG_COLOR pal_checkbox_released[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE_41,
    C_WHITE_41,
    /* Frame 2 */
    C_WHITE_89,
    C_WHITE_89,
    C_WHITE_63,
    C_WHITE_63
};

#elif defined(UGUI_USE_COLOR_RGB565)

#if !defined(C_DESKTOP_COLOR)
#define C_DESKTOP_COLOR              0x5C5D
#endif
#if !defined(C_FORE_COLOR)
#define C_FORE_COLOR                 C_BLACK
#endif
#if !defined(C_BACK_COLOR)
#define C_BACK_COLOR                 C_WHITE_94
#endif
#if !defined(C_TITLE_FORE_COLOR)
#define C_TITLE_FORE_COLOR    C_WHITE
#endif
#if !defined(C_TITLE_BACK_COLOR)
#define C_TITLE_BACK_COLOR    C_BLUE
#endif
#if !defined(C_INACTIVE_TITLE_FORE_COLOR)
#define C_INACTIVE_TITLE_FORE_COLOR    C_WHITE
#endif
#if !defined(C_INACTIVE_TITLE_BACK_COLOR)
#define C_INACTIVE_TITLE_BACK_COLOR    C_GRAY
#endif

const UG_COLOR pal_window[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE_41,
    C_WHITE_41,
    /* Frame 2 */
    C_WHITE_89,
    C_WHITE_89,
    C_WHITE_63,
    C_WHITE_63
};

const UG_COLOR pal_button_pressed[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    /* Frame 2 */
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94
};

const UG_COLOR pal_button_released[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE_41,
    C_WHITE_41,
    /* Frame 2 */
    C_WHITE_89,
    C_WHITE_89,
    C_WHITE_63,
    C_WHITE_63
};

const UG_COLOR pal_checkbox_pressed[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    C_WHITE_63,
    /* Frame 2 */
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94,
    C_WHITE_94
};

const UG_COLOR pal_checkbox_released[] = {
    /* Frame 0 */
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    C_WHITE_39,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE_41,
    C_WHITE_41,
    /* Frame 2 */
    C_WHITE_89,
    C_WHITE_89,
    C_WHITE_63,
    C_WHITE_63
};

#elif defined(UGUI_USE_COLOR_BW)

#if !defined(C_DESKTOP_COLOR)
#define C_DESKTOP_COLOR              C_BLACK
#endif
#if !defined(C_FORE_COLOR)
#define C_FORE_COLOR                 C_BLACK
#endif
#if !defined(C_BACK_COLOR)
#define C_BACK_COLOR                 C_WHITE
#endif
#if !defined(C_TITLE_FORE_COLOR)
#define C_TITLE_FORE_COLOR    C_BLACK
#endif
#if !defined(C_TITLE_BACK_COLOR)
#define C_TITLE_BACK_COLOR    C_WHITE
#endif
#if !defined(C_INACTIVE_TITLE_FORE_COLOR)
#define C_INACTIVE_TITLE_FORE_COLOR    C_WHITE
#endif
#if !defined(C_INACTIVE_TITLE_BACK_COLOR)
#define C_INACTIVE_TITLE_BACK_COLOR    C_BLACK
#endif

const UG_COLOR pal_window[] = {
    /* Frame 0 */
    C_BLACK,
    C_BLACK,
    C_BLACK,
    C_BLACK,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_BLACK,
    C_BLACK,
    /* Frame 2 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE
};

const UG_COLOR pal_button_pressed[] = {
    /* Frame 0 */
    C_BLACK,
    C_BLACK,
    C_BLACK,
    C_BLACK,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE,
    /* Frame 2 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE
};

const UG_COLOR pal_button_released[] = {
    /* Frame 0 */
    C_BLACK,
    C_BLACK,
    C_BLACK,
    C_BLACK,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_BLACK,
    C_BLACK,
    /* Frame 2 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE
};

const UG_COLOR pal_checkbox_pressed[] = {
    /* Frame 0 */
    C_BLACK,
    C_BLACK,
    C_BLACK,
    C_BLACK,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE,
    /* Frame 2 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE
};

const UG_COLOR pal_checkbox_released[] = {
    /* Frame 0 */
    C_BLACK,
    C_BLACK,
    C_BLACK,
    C_BLACK,
    /* Frame 1 */
    C_WHITE,
    C_WHITE,
    C_BLACK,
    C_BLACK,
    /* Frame 2 */
    C_WHITE,
    C_WHITE,
    C_WHITE,
    C_WHITE
};
#endif

#endif // __UGUI_THEME_DEFAULT_H