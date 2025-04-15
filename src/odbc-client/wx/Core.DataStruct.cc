module;

#include <wx/gdicmn.h>

export module wx.Core:DataStruct;

namespace wx
{
    export using Size		= wxSize;
    export using Point		= wxPoint;
    export using RealPoint	= wxRealPoint;
    export using Rect		= wxRect;
    export using ColourDatabase = wxColourDatabase;

    export auto const
	DefaultPosition	    = wxDefaultPosition;

    export auto const
	DefaultSize	    = wxDefaultSize;

    export auto const
	&TheColorDatabase   = wxTheColourDatabase;
}
