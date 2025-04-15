module;

#include <wx/persist.h>
#include <wx/persist/window.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/splitter.h>
#include <wx/persist/combobox.h>
#include <wx/persist/treebook.h>
#include <wx/persist/dataview.h>
#include <wx/persist/bookctrl.h>

#include <wx/display.h>

#include <wx/validate.h>
#include <wx/window.h>
#include <wx/nonownedwnd.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>
#include <wx/artprov.h>

export module wx.Core;

#include "intellisense/odbc-client-headers.hh"

#if !defined MSVC_INTELLISENSE
import std;
import wx.Base;

export import :DataStruct;
export import :Defs;
export import :GDI;
export import :Event;
export import :Controls;
export import :Layout;
export import :TopLevel;
#endif

namespace wx
{
    export using Display	    = wxDisplay;
    export using Validator	    = wxValidator;
    export using PersistenceManager = wxPersistenceManager;
    export using PersistentObject   = wxPersistentObject;

    export using Window		= wxWindow;
    export using NonOwnedWindow = wxNonOwnedWindow;
    export using Dialog		= wxDialog;
    export using Frame		= wxFrame;
    export using Panel		= wxPanel;
    export using MenuItem	= wxMenuItem;
    export using Menu		= wxMenu;
    export using MenuBar	= wxMenuBar;
    export using ArtProvider	= wxArtProvider;

    export using NavigationKeyEvent = wxNavigationKeyEvent;

    export using MessageDialog	= wxMessageDialog;

    using std::forward;

#if defined MessageBox
# undef MessageBox
#endif

    export template <typename... Args>
	inline auto MessageBox(Args &&... args)
    {
	return wxMessageBox(forward<Args>(args)...);
    }

    export auto const &MessageBoxCaptionStr = wxMessageBoxCaptionStr;

    export auto const &EVT_WINDOW_MODAL_DIALOG_CLOSED = wxEVT_WINDOW_MODAL_DIALOG_CLOSED;

    export auto const
	&DefaultValidator   = wxDefaultValidator;

    export auto const
	&PanelNameStr	    = wxPanelNameStr;

    export template <typename... Args>
	inline auto CreatePersistentObject(Args &&... args)
    {
	using ::wxCreatePersistentObject;
	using ::wxPersistentRegisterAndRestore;

	return wxCreatePersistentObject(forward<Args>(args)...);
    }

    export template <typename... Args>
	inline auto PersistentRegisterAndRestore(Args &&... args)
    {
	using ::wxCreatePersistentObject;
	using ::wxPersistentRegisterAndRestore;

	return wxPersistentRegisterAndRestore(forward<Args>(args)...);
    }
}
