module;

#include <wx/window.h>
#include <wx/nonownedwnd.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>

#include <wx/control.h>
#include <wx/button.h>
#include <wx/tglbtn.h>
#include <wx/textentry.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/combo.h>
#include <wx/listbox.h>
#include <wx/checklst.h>
#include <wx/imaglist.h>
#include <wx/treectrl.h>
#include <wx/headerctrl.h>
#include <wx/treelist.h>

export module local.wx.Core;

#include "intellisense/odbc-client-headers.hh"

#if !defined MSVC_INTELLISENSE
import std;

export import :defs;
export import :event;
export import :toplevel;
#endif

namespace local::wx
{
    export using Window		= wxWindow;
    export using NonOwnedWindow = wxNonOwnedWindow;
    export using TopLevelWindow = wxTopLevelWindow;
    export using Dialog		= wxDialog;
    export using Frame		= wxFrame;
    export using Panel		= wxPanel;
    export using Menu		= wxMenu;
    export using MenuBar	= wxMenuBar;

    export using Control	= wxControl;
    export using Button		= wxButton;
    export using ToggleButton	= wxToggleButton;
    export using TextEntry	= wxTextEntry;
    export using TextCtrl	= wxTextCtrl;
    export using ComboBox	= wxComboBox;
    export using Combo		= wxComboCtrl;
    export using ListBox	= wxListBox;
    export using CheckListBox	= wxCheckListBox;
    export using ImageList	= wxImageList;
    export using TreeCtrl	= wxTreeCtrl;
    export using HeaderCtrl	= wxHeaderCtrl;
    export using TreeListCtrl	= wxTreeListCtrl;

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
}
