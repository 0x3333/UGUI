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

#define UGUI_DECLARE_FONT(name, varPointer, bpp, width, height) const UG_FONT name = { (UG_U8*) varPointer, bpp, width, height, 0, 255, NULL};

#include "fonts/font_4x6.h"
#include "fonts/font_5x8.h"
#include "fonts/font_5x12.h"
#include "fonts/font_6x8.h"
#include "fonts/font_6x10.h"
#include "fonts/font_7x12.h"
#include "fonts/font_8x8.h"
#include "fonts/font_8x12.h"
#include "fonts/font_8x12_cyrillic.h"
#include "fonts/font_8x14.h"
#include "fonts/font_10x16.h"
#include "fonts/font_12x16.h"
#include "fonts/font_12x20.h"
#include "fonts/font_16x26.h"
#include "fonts/font_22x36.h"
#include "fonts/font_24x40.h"
#include "fonts/font_32x53.h"

#endif // __UGUI_FONTS_H