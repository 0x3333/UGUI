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

#define UGUI_DECLARE_FONT(name, varPointer, width, height) const UG_FONT name = { (unsigned char*) varPointer, FONT_TYPE_1BPP, width, height, 0, 255, NULL};

#ifdef USE_FONT_4X6
   #include "fonts/font_4x6.h"
   UGUI_DECLARE_FONT(FONT_4X6, font_4x6, 4, 6)
#endif
#ifdef USE_FONT_5X8
   #include "fonts/font_5x8.h"
   UGUI_DECLARE_FONT(FONT_5X8, font_5x8, 5, 8)
#endif
#ifdef USE_FONT_5X12
   #include "fonts/font_5x12.h"
   UGUI_DECLARE_FONT(FONT_5X12, font_5x12, 5, 12)
#endif
#ifdef USE_FONT_6X8
   #include "fonts/font_6x8.h"
   UGUI_DECLARE_FONT(FONT_6X8, font_6x8, 6, 8)
#endif
#ifdef USE_FONT_6X10
   #include "fonts/font_6x10.h"
   UGUI_DECLARE_FONT(FONT_6X10, font_6x10, 6, 10)
#endif
#ifdef USE_FONT_7X12
   #include "fonts/font_7x12.h"
   UGUI_DECLARE_FONT(FONT_7X12, font_7x12, 7, 12)
#endif
#ifdef USE_FONT_8X8
   #include "fonts/font_8x8.h"
   UGUI_DECLARE_FONT(FONT_8X8, font_8x8, 8, 8)
#endif
#ifdef USE_FONT_8X12
   #include "fonts/font_8x12.h"
   UGUI_DECLARE_FONT(FONT_8X12, font_8x12, 8, 12)
#endif
#ifdef USE_FONT_8X12_CYRILLIC
   #include "fonts/font_8x12_cyrillic.h"
   UGUI_DECLARE_FONT(FONT_8X12_CYRILLIC, font_8x12_cyrillic, 8, 12)
#endif
#ifdef USE_FONT_8X14
   #include "fonts/font_8x14.h"
   UGUI_DECLARE_FONT(FONT_8X14, font_8x14, 8, 14)
#endif
#ifdef USE_FONT_10X16
   #include "fonts/font_10x16.h"
   UGUI_DECLARE_FONT(FONT_10X16, font_10x16, 10, 16)
#endif
#ifdef USE_FONT_12X16
   #include "fonts/font_12x16.h"
   UGUI_DECLARE_FONT(FONT_12X16, font_12x16, 12, 16)
#endif
#ifdef USE_FONT_12X20
   #include "fonts/font_12x20.h"
   UGUI_DECLARE_FONT(FONT_12X20, font_12x20, 12, 20)
#endif
#ifdef USE_FONT_16X26
   #include "fonts/font_16x26.h"
   UGUI_DECLARE_FONT(FONT_16X26, font_16x26, 16, 26)
#endif
#ifdef USE_FONT_22X36
   #include "fonts/font_22x36.h"
   UGUI_DECLARE_FONT(FONT_22X36, font_22x36, 22, 36)
#endif
#ifdef USE_FONT_24X40
   #include "fonts/font_24x40.h"
   UGUI_DECLARE_FONT(FONT_24X40, font_24x40, 24, 40)
#endif
#ifdef USE_FONT_32X53
   #include "fonts/font_32x53.h"
   UGUI_DECLARE_FONT(FONT_32X53, font_32x53, 32, 53)
#endif

#endif // __UGUI_FONTS_H