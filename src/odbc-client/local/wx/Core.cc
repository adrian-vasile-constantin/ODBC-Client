module;

#include <wx/display.h>

#include <wx/validate.h>
#include <wx/window.h>
#include <wx/nonownedwnd.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>

export module local.wx.Core;

#include "intellisense/odbc-client-headers.hh"

#if !defined MSVC_INTELLISENSE
import std;

export import :DataStruct;
export import :Defs;
export import :GDI;
export import :Event;
export import :Controls;
export import :Layout;
export import :TopLevel;
#endif

namespace local::wx
{
    export using Display	= wxDisplay;
    export using Validator	= wxValidator;

    export using Window		= wxWindow;
    export using NonOwnedWindow = wxNonOwnedWindow;
    export using Dialog		= wxDialog;
    export using Frame		= wxFrame;
    export using Panel		= wxPanel;
    export using MenuItem	= wxMenuItem;
    export using Menu		= wxMenu;
    export using MenuBar	= wxMenuBar;

    export using MessageDialog	= wxMessageDialog;

    using std::forward;

#if defined MessageBox
# undef MessageBox
#endif

    export template<typename... Args>
	inline auto MessageBox(Args &&... args)
    {
	return wxMessageBox(forward<Args>(args)...);
    }

    export auto const &MessageBoxCaptionStr = wxMessageBoxCaptionStr;

    export auto const &EVT_WINDOW_MODAL_DIALOG_CLOSED = wxEVT_WINDOW_MODAL_DIALOG_CLOSED;

    export auto const
	&DefaultValidator = wxDefaultValidator;
}
