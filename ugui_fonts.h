#ifndef __UGUI_FONTS_H
#define __UGUI_FONTS_H

#include <stdlib.h>

/* -------------------------------------------------------------------------------- */
/* -- µGUI FONTS                                                                 -- */
/* -- Source: http://www.mikrocontroller.net/user/show/benedikt                  -- */
/* -------------------------------------------------------------------------------- */
typedef enum
{
	FONT_TYPE_1BPP,
	FONT_TYPE_8BPP
} FONT_TYPE;

typedef struct
{
   unsigned char* p;
   FONT_TYPE font_type;
   UG_S16 char_width;
   UG_S16 char_height;
   UG_U16 start_char;
   UG_U16 end_char;
   UG_U8  *widths;
} UG_FONT;

#define UGUI_DECLARE_FONT(name, varPointer, bpp, width, height) const UG_FONT name = { (unsigned char*) varPointer, bpp, width, height, 0, 255, NULL};

#ifdef UGUI_USE_FONT_4X6
   #include "fonts/font_4x6.h"
   UGUI_DECLARE_FONT(FONT_4X6, _font_4x6, FONT_TYPE_1BPP, 4, 6)
#endif
#ifdef UGUI_USE_FONT_5X8
   #include "fonts/font_5x8.h"
   UGUI_DECLARE_FONT(FONT_5X8, _font_5x8, FONT_TYPE_1BPP, 5, 8)
#endif
#ifdef UGUI_USE_FONT_5X12
   #include "fonts/font_5x12.h"
   UGUI_DECLARE_FONT(FONT_5X12, _font_5x12, FONT_TYPE_1BPP, 5, 12)
#endif
#ifdef UGUI_USE_FONT_6X8
   #include "fonts/font_6x8.h"
   UGUI_DECLARE_FONT(FONT_6X8, _font_6x8, FONT_TYPE_1BPP, 6, 8)
#endif
#ifdef UGUI_USE_FONT_6X10
   #include "fonts/font_6x10.h"
   UGUI_DECLARE_FONT(FONT_6X10, _font_6x10, FONT_TYPE_1BPP, 6, 10)
#endif
#ifdef UGUI_USE_FONT_7X12
   #include "fonts/font_7x12.h"
   UGUI_DECLARE_FONT(FONT_7X12, _font_7x12, FONT_TYPE_1BPP, 7, 12)
#endif
#ifdef UGUI_USE_FONT_8X8
   #include "fonts/font_8x8.h"
   UGUI_DECLARE_FONT(FONT_8X8, _font_8x8, FONT_TYPE_1BPP, 8, 8)
#endif
#ifdef UGUI_USE_FONT_8X12
   #include "fonts/font_8x12.h"
   UGUI_DECLARE_FONT(FONT_8X12, _font_8x12, FONT_TYPE_1BPP, 8, 12)
#endif
#ifdef UGUI_USE_FONT_8X12_CYRILLIC
   #include "fonts/font_8x12_cyrillic.h"
   UGUI_DECLARE_FONT(FONT_8X12_CYRILLIC, _font_8x12_cyrillic, FONT_TYPE_1BPP, 8, 12)
#endif
#ifdef UGUI_USE_FONT_8X14
   #include "fonts/font_8x14.h"
   UGUI_DECLARE_FONT(FONT_8X14, _font_8x14, FONT_TYPE_1BPP, 8, 14)
#endif
#ifdef UGUI_USE_FONT_10X16
   #include "fonts/font_10x16.h"
   UGUI_DECLARE_FONT(FONT_10X16, _font_10x16, FONT_TYPE_1BPP, 10, 16)
#endif
#ifdef UGUI_USE_FONT_12X16
   #include "fonts/font_12x16.h"
   UGUI_DECLARE_FONT(FONT_12X16, _font_12x16, FONT_TYPE_1BPP, 12, 16)
#endif
#ifdef UGUI_USE_FONT_12X20
   #include "fonts/font_12x20.h"
   UGUI_DECLARE_FONT(FONT_12X20, _font_12x20, FONT_TYPE_1BPP, 12, 20)
#endif
#ifdef UGUI_USE_FONT_16X26
   #include "fonts/font_16x26.h"
   UGUI_DECLARE_FONT(FONT_16X26, _font_16x26, FONT_TYPE_1BPP, 16, 26)
#endif
#ifdef UGUI_USE_FONT_22X36
   #include "fonts/font_22x36.h"
   UGUI_DECLARE_FONT(FONT_22X36, _font_22x36, FONT_TYPE_1BPP, 22, 36)
#endif
#ifdef UGUI_USE_FONT_24X40
   #include "fonts/font_24x40.h"
   UGUI_DECLARE_FONT(FONT_24X40, _font_24x40, FONT_TYPE_1BPP, 24, 40)
#endif
#ifdef UGUI_USE_FONT_32X53
   #include "fonts/font_32x53.h"
   UGUI_DECLARE_FONT(FONT_32X53, _font_32x53, FONT_TYPE_1BPP, 32, 53)
#endif

#endif // __UGUI_FONTS_H