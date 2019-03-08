#ifndef __UGUI_CONFIG_H
#define __UGUI_CONFIG_H

/* -------------------------------------------------------------------------------- */
/* -- CONFIG SECTION                                                             -- */
/* -------------------------------------------------------------------------------- */

#include <stdint.h>

/* Enable color mode */
// #define UGUI_USE_COLOR_RGB888   // RGB = 0xFF,0xFF,0xFF
// #define UGUI_USE_COLOR_RGB565   // RGB = 0bRRRRRGGGGGGBBBBB
// #define UGUI_USE_COLOR_BW   // BW = 0x00|0xFF

/* Enable Touch Support */
// #define UGUI_USE_TOUCH

/* Enable Console Support */
#define UGUI_USE_CONSOLE

/* Enable needed fonts */
#define __UG_FONT_DATA const

// #define UGUI_USE_FONT_4X6
// #define UGUI_USE_FONT_5X8
// #define UGUI_USE_FONT_5X12
// #define UGUI_USE_FONT_6X8
// #define UGUI_USE_FONT_6X10
// #define UGUI_USE_FONT_7X12
// #define UGUI_USE_FONT_8X8
// #define UGUI_USE_FONT_8X12_CYRILLIC
// #define UGUI_USE_FONT_8X12
// #define UGUI_USE_FONT_8X14
// #define UGUI_USE_FONT_10X16
// #define UGUI_USE_FONT_12X16
// #define UGUI_USE_FONT_12X20
// #define UGUI_USE_FONT_16X26
// #define UGUI_USE_FONT_22X36
// #define UGUI_USE_FONT_24X40
// #define UGUI_USE_FONT_32X53

/* Feature enablers */
// #define UGUI_USE_PRERENDER_EVENT
// #define UGUI_USE_POSTRENDER_EVENT
// #define UGUI_USE_MULTITASKING

/* Specify platform-dependent integer types here */

typedef uint8_t      UG_U8;
typedef int8_t       UG_S8;
typedef uint16_t     UG_U16;
typedef int16_t      UG_S16;
typedef uint32_t     UG_U32;
typedef int32_t      UG_S32;

/* Example for dsPIC33
typedef unsigned char         UG_U8;
typedef signed char           UG_S8;
typedef unsigned int          UG_U16;
typedef signed int            UG_S16;
typedef unsigned long int     UG_U32;
typedef signed long int       UG_S32;
*/

#endif //__UGUI_CONFIG_H
