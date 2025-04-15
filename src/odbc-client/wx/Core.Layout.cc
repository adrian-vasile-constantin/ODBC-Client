module;

#include <wx/sizer.h>
#include <wx/wrapsizer.h>
#include <wx/gbsizer.h>

export module wx.Core:Layout;

namespace wx
{
    export using SizerFlags		= wxSizerFlags;
    export using Sizer			= wxSizer;
    export using SizerItem		= wxSizerItem;
    export using BoxSizer		= wxBoxSizer;
    export using StaticBoxSizer		= wxStaticBoxSizer;
    export using StdDialogButtonSizer	= wxStdDialogButtonSizer;
    export using WrapSizer		= wxWrapSizer;
    export using GridSizer		= wxGridSizer;
    export using FlegGridSizer		= wxFlexGridSizer;
    export using GridBagSizer		= wxGridBagSizer;
    export using GBSizerItem		= wxGBSizerItem;
    export using GBPosition		= wxGBPosition;
    export using GBSpan			= wxGBSpan;

    export constexpr auto const
	TOP				= wxTOP,
	BOTTOM				= wxBOTTOM,
	LEFT				= wxLEFT,
	RIGHT				= wxRIGHT,
	ALL				= wxALL;

    export constexpr auto const
	EXPAND				= wxEXPAND,
	SHAPED				= wxSHAPED;

    export constexpr auto const
	HORIZONTAL			= wxHORIZONTAL,
	VERTICAL			= wxVERTICAL;

    export constexpr auto const
	FIXED_MINSIZE			= wxFIXED_MINSIZE,
	RESERVE_SPACE_EVEN_IF_HIDDEN	= wxRESERVE_SPACE_EVEN_IF_HIDDEN;

    export constexpr auto const
	ALIGN_CENTER			= wxALIGN_CENTER,
	ALIGN_CENTRE			= wxALIGN_CENTRE,
	ALIGN_LEFT			= wxALIGN_LEFT,
	ALIGN_RIGHT			= wxALIGN_RIGHT,
	ALIGN_TOP			= wxALIGN_TOP,
	ALIGN_BOTTOM			= wxALIGN_BOTTOM,
	ALIGN_CENTER_VERTICAL		= wxALIGN_CENTER_VERTICAL,
	ALIGN_CENTRE_VERTICAL		= wxALIGN_CENTRE_VERTICAL,
	ALIGN_CENTER_HORIZONTAL		= wxALIGN_CENTER_HORIZONTAL,
	ALIGN_CENTRE_HORIZONTAL		= wxALIGN_CENTRE_HORIZONTAL;

    export auto const
	&DefaultSpan			= wxDefaultSpan;
}
