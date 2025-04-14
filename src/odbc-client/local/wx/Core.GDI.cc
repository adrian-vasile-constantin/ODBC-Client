module;

#include <wx/image.h>
#include <wx/gdiobj.h>
#include <wx/bitmap.h>
#include <wx/brush.h>
#include <wx/cursor.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/iconbndl.h>
#include <wx/palette.h>
#include <wx/pen.h>
#include <wx/region.h>

export module local.wx.Core:GDI;

namespace local::wx
{
    export using Image		    = wxImage;
    export using ImageHandler	    = wxImageHandler;

    export inline auto InitAllImageHandlers()
    {
	return wxInitAllImageHandlers();
    }

    export using GDIObject	    = wxGDIObject;

    export using Bitmap		    = wxBitmap;
    export using Brush		    = wxBrush;
    export using BrushList	    = wxBrushList;
    export using Cursor		    = wxCursor;

    export using FontInfo	    = wxFontInfo;
    export using Font		    = wxFont;
    export using FontList	    = wxFontList;
    export using FontFamily	    = wxFontFamily;
    export using FontStyle	    = wxFontStyle;
    export using FontWeight	    = wxFontWeight;
    export using FontSymbolicSize   = wxFontSymbolicSize;
    export using FontFlag	    = wxFontFlag;
    export using FontEncoding	    = wxFontEncoding;

    export using Icon		    = wxIcon;
    export using IconBundle	    = wxIconBundle;
    export using Palette	    = wxPalette;
    export using Pen		    = wxPen;
    export using Region		    = wxRegion;
    export using RegionIterator	    = wxRegionIterator;
    export using RegionContain	    = wxRegionContain;

    export auto const
	&NullImage		= wxNullImage;

    export auto const
	&NullBitmap		= wxNullBitmap;

    export auto const
	&NullBrush		= wxNullBrush;

    export auto const
	&TheBrushList		= wxTheBrushList;

    export auto const
	&BLACK_BRUSH		= wxBLACK_BRUSH,
	&BLUE_BRUSH		= wxBLUE_BRUSH,
	&CYAN_BRUSH		= wxCYAN_BRUSH,
	&GREEN_BRUSH		= wxGREEN_BRUSH,
	&YELLOW_BRUSH		= wxYELLOW_BRUSH,
	&GREY_BRUSH		= wxGREY_BRUSH,
	&LIGHT_GREY_BRUSH	= wxLIGHT_GREY_BRUSH,
	&MEDIUM_GREY_BRUSH	= wxMEDIUM_GREY_BRUSH,
	&RED_BRUSH		= wxRED_BRUSH,
	&TRANSPARENT_BRUSH	= wxTRANSPARENT_BRUSH,
	&WHITE_BRUSH		= wxWHITE_BRUSH;

    export auto const
	&NullCursor		= wxNullCursor;

    export auto const
	&STANDARD_CURSOR	= wxSTANDARD_CURSOR,
	&HOURGLASS_CURSOR	= wxHOURGLASS_CURSOR,
	&CROSS_CURSOR		= wxCROSS_CURSOR;

    export auto const
	&NullFont		= wxNullFont;

    export auto const
	&TheFontList		= wxTheFontList;

    export auto const
	&NORMAL_FONT		= wxNORMAL_FONT,
	&SMALL_FONT		= wxSMALL_FONT,
	ITALIC_FONT		= wxITALIC_FONT,
	SWISS_FONT		= wxSWISS_FONT;

    export auto const
	&NullIcon		= wxNullIcon;

    export auto const
	&NullIconBundle		= wxNullIconBundle;

    export auto const
	&NullPalette		= wxNullPalette;

    export auto const
	&NullPen		= wxNullPen;

    export auto const
	&BLACK_DASHED_PEN	= wxBLACK_DASHED_PEN,
	&BLACK_PEN		= wxBLACK_PEN,
	&BLUE_PEN		= wxBLUE_PEN,
	&CYAN_PEN		= wxCYAN_PEN,
	&GREEN_PEN		= wxGREEN_PEN,
	&YELLOW_PEN		= wxYELLOW_PEN,
	&GREY_PEN		= wxGREY_PEN,
	&LIGHT_GREY_PEN		= wxLIGHT_GREY_PEN,
	&MEDIUM_GREY_PEN	= wxMEDIUM_GREY_PEN,
	&RED_PEN		= wxRED_PEN,
	&TRANSPARENT_PEN	= wxTRANSPARENT_PEN,
	&WHITE_PEN		= wxWHITE_PEN;

    // export auto const
    //	&NullRegion		= wxNullRegion;
}
