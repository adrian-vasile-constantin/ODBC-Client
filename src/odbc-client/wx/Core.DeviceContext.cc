module;

#include <wx/dc.h>
#include <wx/dcclient.h>

export module wx.Core:DeviceContext;

namespace wx
{
    export using DC	    = wxDC;
    export using WindowDC   = wxWindowDC;
    export using ClientDC   = wxClientDC;
    export using PaintDC    = wxPaintDC;
}
