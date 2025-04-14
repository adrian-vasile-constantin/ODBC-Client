module;

#include <wx/toplevel.h>

export module local.wx.Core:TopLevel;

namespace local::wx
{
    export using TopLevelWindow	    = wxTopLevelWindow;

    export auto const
	DEFAULT_FRAME_STYLE	    = wxDEFAULT_FRAME_STYLE;

    export auto const
	USER_ATTENTION_INFO	    = wxUSER_ATTENTION_INFO,
	USER_ATTENTION_ERROR	    = wxUSER_ATTENTION_ERROR;

    export using ContentProtection  = wxContentProtection;

    export auto const
	CONTENT_PROTECTION_NONE	    = wxCONTENT_PROTECTION_NONE,
	CONTENT_PROTECTION_ENABLED  = wxCONTENT_PROTECTION_ENABLED;

    export auto const
	FULLSCREEN_NOMENUBAR	    = wxFULLSCREEN_NOMENUBAR,
	FULLSCREEN_NOTOOLBAR	    = wxFULLSCREEN_NOTOOLBAR,
	FULLSCREEN_NOSTATUSB	    = wxFULLSCREEN_NOSTATUSBAR,
	FULLSCREEN_NOBORDER 	    = wxFULLSCREEN_NOBORDER,
	FULLSCREEN_NOCAPTION	    = wxFULLSCREEN_NOCAPTION,
	FULLSCREEN_ALL      	    = wxFULLSCREEN_ALL;

    export auto const STAY_ON_TOP   = wxSTAY_ON_TOP;
    export auto const ICONIZE	    = wxICONIZE;

    export auto const ICONSIZE	    = wxICONIZE;
    export auto const MINIMIZE	    = wxMINIMIZE;
    export auto const MAXIMIZE	    = wxMAXIMIZE;
    export auto const CLOSE_BOX	    = wxCLOSE_BOX;
    export auto const SYSTEM_MENU   = wxSYSTEM_MENU;
    export auto const MINIMIZE_BOX  = wxMINIMIZE_BOX;
    export auto const MAXIMIZE_BOX  = wxMAXIMIZE_BOX;
    export auto const TINY_CAPTION  = wxTINY_CAPTION;
    export auto const RESIZE_BORDER = wxRESIZE_BORDER;
}
