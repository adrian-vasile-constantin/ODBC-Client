#if !defined ODBC_CLIENT_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
#define ODBC_CLIENT_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED

#if defined __INTELLISENSE__

// For MS IntelliSense only

# if !defined MSVC_INTELLISENSE
#  define MSVC_INTELLISENSE 1
# endif

#if defined WINDOWS
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif

# if defined(_M_IX86) && !defined(_X86_)
#  define _X86_
# endif
#endif

#include <utility>
#include <memory>

#include <wx/string.h>
#include <wx/secretstore.h>
#include <wx/object.h>
#include <wx/event.h>
#include <wx/app.h>

#include <wx/defs.h>
#include <wx/window.h>
#include <wx/nonownedwnd.h>
#include <wx/toplevel.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>

// #include "intellisense/odbcxx_project_headers.hh"

#include "OdbcFrame.hh"

namespace wx
{
    using EventType	    = wxEventType;

    using SecretStore	    = wxSecretStore;
    using SecretValue	    = wxSecretValue;
    using SecretString	    = wxSecretString;
    using String	    = wxString;
    using Object	    = wxObject;
    using Event		    = wxEvent;
    using AppConsole	    = wxAppConsole;
    using App		    = wxApp;

    using CommandEvent	    = wxCommandEvent;
    using CloseEvent	    = wxCloseEvent;
    using PaintEvent	    = wxPaintEvent;
    using MaximizeEvent	    = wxMaximizeEvent;
    using FullScreenEvent   = wxFullScreenEvent;
    using EraseEvent	    = wxEraseEvent;
    using FocusEvent	    = wxFocusEvent;

    using Window	    = wxWindow;
    using NonOwnedWindow    = wxNonOwnedWindow;
    using TopLevelWindow    = wxTopLevelWindow;
    using Dialog	    = wxDialog;
    using Frame		    = wxFrame;
    using Panel		    = wxPanel;
    using Menu		    = wxMenu;
    using MenuBar	    = wxMenuBar;
    using MessageDialog	    = wxMessageDialog;

    using std::forward;

#if defined MessageBox
# undef MessageBox
#endif

    template<typename... Args>
	inline auto MessageBox(Args && ...args)
    {
	return wxMessageBox(forward<Args>(args)...);
    }

    auto const &MessageBoxCaptionStr = wxMessageBoxCaptionStr;

    auto const SIZE_AUTO_WIDTH	 	  = wxSIZE_AUTO_WIDTH;
    auto const SIZE_AUTO_HEIGHT           = wxSIZE_AUTO_HEIGHT;
    auto const SIZE_AUTO                  = wxSIZE_AUTO;
    auto const SIZE_USE_EXISTING          = wxSIZE_USE_EXISTING;
    auto const SIZE_ALLOW_MINUS_ONE       = wxSIZE_ALLOW_MINUS_ONE;
    auto const SIZE_NO_ADJUSTMENTS        = wxSIZE_NO_ADJUSTMENTS;
    auto const SIZE_FORCE                 = wxSIZE_FORCE;
    auto const SIZE_FORCE_EVENT           = wxSIZE_FORCE_EVENT;
    auto const VSCROLL                    = wxVSCROLL;
    auto const HSCROLL                    = wxHSCROLL;
    auto const CAPTION                    = wxCAPTION;
    auto const DOUBLE_BORDER              = wxDOUBLE_BORDER;
    auto const SUNKEN_BORDER              = wxSUNKEN_BORDER;
    auto const RAISED_BORDER              = wxRAISED_BORDER;
    auto const BORDER                     = wxBORDER;
    auto const SIMPLE_BORDER              = wxSIMPLE_BORDER;
    auto const STATIC_BORDER              = wxSTATIC_BORDER;
    auto const NO_BORDER                  = wxNO_BORDER;
    auto const ALWAYS_SHOW_SB             = wxALWAYS_SHOW_SB;
    auto const CLIP_CHILDREN              = wxCLIP_CHILDREN;
    auto const CLIP_SIBLINGS              = wxCLIP_SIBLINGS;
    auto const TRANSPARENT_WINDOW         = wxTRANSPARENT_WINDOW;
    auto const TAB_TRAVERSAL              = wxTAB_TRAVERSAL;
    auto const WANTS_CHARS                = wxWANTS_CHARS;
    auto const RETAINED                   = wxRETAINED;
    auto const BACKINGSTORE               = wxBACKINGSTORE;
    auto const POPUP_WINDOW               = wxPOPUP_WINDOW;
    auto const FULL_REPAINT_ON_RESIZE     = wxFULL_REPAINT_ON_RESIZE;
    auto const NO_FULL_REPAINT_ON_RESIZE  = wxNO_FULL_REPAINT_ON_RESIZE;
    auto const WINDOW_STYLE_MASK          = wxWINDOW_STYLE_MASK;
    auto const WS_EX_BLOCK_EVENTS         = wxWS_EX_BLOCK_EVENTS;
    auto const WS_EX_TRANSIENT            = wxWS_EX_TRANSIENT;
    auto const WS_EX_THEMED_BACKGROUND    = wxWS_EX_THEMED_BACKGROUND;
    auto const WS_EX_PROCESS_IDLE         = wxWS_EX_PROCESS_IDLE;
    auto const WS_EX_PROCESS_UI_UPDATES   = wxWS_EX_PROCESS_UI_UPDATES;
    auto const FRAME_EX_METAL             = wxFRAME_EX_METAL;
    auto const DIALOG_EX_METAL            = wxDIALOG_EX_METAL;

#if defined WS_EX_CONTEXTHELP
# undef WS_EX_CONTEXTHELP
#endif

    auto const WS_EX_CONTEXTHELP          = wxWS_EX_CONTEXTHELP;
    auto const FRAME_EX_CONTEXTHELP       = wxFRAME_EX_CONTEXTHELP;
    auto const DIALOG_EX_CONTEXTHELP      = wxDIALOG_EX_CONTEXTHELP;
    auto const FRAME_DRAWER               = wxFRAME_DRAWER;
    auto const FRAME_NO_WINDOW_MENU       = wxFRAME_NO_WINDOW_MENU;
    auto const MB_DOCKABLE                = wxMB_DOCKABLE;
    auto const MENU_TEAROFF               = wxMENU_TEAROFF;
    auto const COLOURED                   = wxCOLOURED;
    auto const FIXED_LENGTH               = wxFIXED_LENGTH;
    auto const LB_SORT                    = wxLB_SORT;
    auto const LB_SINGLE                  = wxLB_SINGLE;
    auto const LB_MULTIPLE                = wxLB_MULTIPLE;
    auto const LB_EXTENDED                = wxLB_EXTENDED;
    auto const LB_NEEDED_SB               = wxLB_NEEDED_SB;
    auto const LB_OWNERDRAW               = wxLB_OWNERDRAW;
    auto const LB_ALWAYS_SB               = wxLB_ALWAYS_SB;
    auto const LB_NO_SB                   = wxLB_NO_SB;
    auto const LB_HSCROLL                 = wxLB_HSCROLL;
    auto const LB_INT_HEIGHT              = wxLB_INT_HEIGHT;
    auto const CB_SIMPLE                  = wxCB_SIMPLE;
    auto const CB_SORT                    = wxCB_SORT;
    auto const CB_READONLY                = wxCB_READONLY;
    auto const CB_DROPDOWN                = wxCB_DROPDOWN;
    auto const RA_LEFTTORIGHT             = wxRA_LEFTTORIGHT;
    auto const RA_TOPTOBOTTOM             = wxRA_TOPTOBOTTOM;
    auto const RA_SPECIFY_COLS            = wxRA_SPECIFY_COLS;
    auto const RA_SPECIFY_ROWS            = wxRA_SPECIFY_ROWS;
    auto const RA_HORIZONTAL              = wxRA_HORIZONTAL;
    auto const RA_VERTICAL                = wxRA_VERTICAL;
    auto const RB_GROUP                   = wxRB_GROUP;
    auto const RB_SINGLE                  = wxRB_SINGLE;
    auto const SB_HORIZONTAL              = wxSB_HORIZONTAL;
    auto const SB_VERTICAL                = wxSB_VERTICAL;
    auto const SP_HORIZONTAL              = wxSP_HORIZONTAL;
    auto const SP_VERTICAL                = wxSP_VERTICAL;
    auto const SP_ARROW_KEYS              = wxSP_ARROW_KEYS;
    auto const SP_WRAP                    = wxSP_WRAP;
    auto const TC_RIGHTJUSTIFY            = wxTC_RIGHTJUSTIFY;
    auto const TC_FIXEDWIDTH              = wxTC_FIXEDWIDTH;
    auto const TC_TOP                     = wxTC_TOP;
    auto const TC_LEFT                    = wxTC_LEFT;
    auto const TC_RIGHT                   = wxTC_RIGHT;
    auto const TC_BOTTOM                  = wxTC_BOTTOM;
    auto const TC_MULTILINE               = wxTC_MULTILINE;
    auto const TC_OWNERDRAW               = wxTC_OWNERDRAW;
    auto const BI_EXPAND                  = wxBI_EXPAND;
    auto const LI_HORIZONTAL              = wxLI_HORIZONTAL;
    auto const LI_VERTICAL                = wxLI_VERTICAL;
    auto const YES                        = wxYES;
    auto const OK                         = wxOK;
    auto const NO                         = wxNO;
    auto const YES_NO                     = wxYES_NO;
    auto const CANCEL                     = wxCANCEL;
    auto const APPLY                      = wxAPPLY;
    auto const CLOSE                      = wxCLOSE;
    auto const OK_DEFAULT                 = wxOK_DEFAULT;
    auto const YES_DEFAULT                = wxYES_DEFAULT;
    auto const NO_DEFAULT                 = wxNO_DEFAULT;
    auto const CANCEL_DEFAULT             = wxCANCEL_DEFAULT;
    auto const ICON_EXCLAMATION           = wxICON_EXCLAMATION;
    auto const ICON_HAND                  = wxICON_HAND;
    auto const ICON_WARNING               = wxICON_WARNING;
    auto const ICON_ERROR                 = wxICON_ERROR;
    auto const ICON_QUESTION              = wxICON_QUESTION;
    auto const ICON_INFORMATION           = wxICON_INFORMATION;
    auto const ICON_STOP                  = wxICON_STOP;
    auto const ICON_ASTERISK              = wxICON_ASTERISK;
    auto const HELP                       = wxHELP;
    auto const FORWARD                    = wxFORWARD;
    auto const BACKWARD                   = wxBACKWARD;
    auto const RESET                      = wxRESET;
    auto const MORE                       = wxMORE;
    auto const SETUP                      = wxSETUP;
    auto const ICON_NONE                  = wxICON_NONE;
    auto const ICON_AUTH_NEEDED           = wxICON_AUTH_NEEDED;
    auto const ICON_MASK                  = wxICON_MASK;
    auto const NOT_FOUND                  = wxNOT_FOUND;
    auto const PRINT_QUALITY_HIGH         = wxPRINT_QUALITY_HIGH;
    auto const PRINT_QUALITY_MEDIUM       = wxPRINT_QUALITY_MEDIUM;
    auto const PRINT_QUALITY_LOW          = wxPRINT_QUALITY_LOW;
    auto const PRINT_QUALITY_DRAFT        = wxPRINT_QUALITY_DRAFT;
    auto const STAY_ON_TOP                = wxSTAY_ON_TOP;
    auto const ICONIZE                    = wxICONIZE;

    auto const ICONSIZE	   	 	  = wxICONIZE;
    auto const MINIMIZE	   	 	  = wxMINIMIZE;
    auto const MAXIMIZE     	 	  = wxMAXIMIZE;
    auto const CLOSE_BOX    	 	  = wxCLOSE_BOX;
    auto const SYSTEM_MENU  	 	  = wxSYSTEM_MENU;
    auto const MINIMIZE_BOX 	 	  = wxMINIMIZE_BOX;
    auto const MAXIMIZE_BOX 	 	  = wxMAXIMIZE_BOX;
    auto const TINY_CAPTION 	 	  = wxTINY_CAPTION;
    auto const RESIZE_BORDER	 	  = wxRESIZE_BORDER;

    using StandardID = wxStandardID;

    auto const
	ID_AUTO_LOWEST		     =  wxID_AUTO_LOWEST,
        ID_AUTO_HIGHEST	    	     =  wxID_AUTO_HIGHEST,
        ID_NONE		    	     =  wxID_NONE,
        ID_SEPARATOR	    	     =  wxID_SEPARATOR,
        ID_ANY		    	     =  wxID_ANY,
        ID_LOWEST	    	     =  wxID_LOWEST,
        ID_OPEN		    	     =  wxID_OPEN,
        ID_CLOSE	    	     =  wxID_CLOSE,
        ID_NEW		    	     =  wxID_NEW,
        ID_SAVE		    	     =  wxID_SAVE,
        ID_SAVEAS	    	     =  wxID_SAVEAS,
        ID_REVERT	    	     =  wxID_REVERT,
        ID_EXIT		    	     =  wxID_EXIT,
        ID_UNDO		    	     =  wxID_UNDO,
        ID_REDO		    	     =  wxID_REDO,
        ID_HELP		    	     =  wxID_HELP,
        ID_PRINT	    	     =  wxID_PRINT,
        ID_PRINT_SETUP	    	     =  wxID_PRINT_SETUP,
        ID_PAGE_SETUP	    	     =  wxID_PAGE_SETUP,
        ID_PREVIEW	    	     =  wxID_PREVIEW,
        ID_ABOUT	    	     =  wxID_ABOUT,
        ID_HELP_CONTENTS    	     =  wxID_HELP_CONTENTS,
        ID_HELP_INDEX	    	     =  wxID_HELP_INDEX,
        ID_HELP_SEARCH	    	     =  wxID_HELP_SEARCH,
        ID_HELP_COMMANDS    	     =  wxID_HELP_COMMANDS,
        ID_HELP_PROCEDURES  	     =  wxID_HELP_PROCEDURES,
        ID_HELP_CONTEXT	    	     =  wxID_HELP_CONTEXT,
        ID_CLOSE_ALL	    	     =  wxID_CLOSE_ALL,
        ID_PREFERENCES	    	     =  wxID_PREFERENCES,
        ID_EDIT		    	     =  wxID_EDIT,
        ID_CUT		    	     =  wxID_CUT,
        ID_COPY		    	     =  wxID_COPY,
        ID_PASTE	    	     =  wxID_PASTE,
        ID_CLEAR	    	     =  wxID_CLEAR,
        ID_FIND		    	     =  wxID_FIND,
        ID_DUPLICATE	    	     =  wxID_DUPLICATE,
        ID_SELECTALL	    	     =  wxID_SELECTALL,
        ID_DELETE	    	     =  wxID_DELETE,
        ID_REPLACE	    	     =  wxID_REPLACE,
        ID_REPLACE_ALL	    	     =  wxID_REPLACE_ALL,
        ID_PROPERTIES	    	     =  wxID_PROPERTIES,
        ID_VIEW_DETAILS	    	     =  wxID_VIEW_DETAILS,
        ID_VIEW_LARGEICONS  	     =  wxID_VIEW_LARGEICONS,
        ID_VIEW_SMALLICONS  	     =  wxID_VIEW_SMALLICONS,
        ID_VIEW_LIST	    	     =  wxID_VIEW_LIST,
        ID_VIEW_SORTDATE    	     =  wxID_VIEW_SORTDATE,
        ID_VIEW_SORTNAME    	     =  wxID_VIEW_SORTNAME,
        ID_VIEW_SORTSIZE    	     =  wxID_VIEW_SORTSIZE,
        ID_VIEW_SORTTYPE    	     =  wxID_VIEW_SORTTYPE,
        ID_FILE			     =  wxID_FILE,
        ID_FILE1		     =  wxID_FILE1,
        ID_FILE2		     =  wxID_FILE2,
        ID_FILE3		     =  wxID_FILE3,
        ID_FILE4		     =  wxID_FILE4,
        ID_FILE5		     =  wxID_FILE5,
        ID_FILE6		     =  wxID_FILE6,
        ID_FILE7		     =  wxID_FILE7,
        ID_FILE8		     =  wxID_FILE8,
        ID_FILE9		     =  wxID_FILE9,
        ID_OK			     =  wxID_OK,
        ID_CANCEL		     =  wxID_CANCEL,
        ID_APPLY		     =  wxID_APPLY,
        ID_YES			     =  wxID_YES,
        ID_NO			     =  wxID_NO,
        ID_STATIC		     =  wxID_STATIC,
        ID_FORWARD		     =  wxID_FORWARD,
        ID_BACKWARD		     =  wxID_BACKWARD,
        ID_DEFAULT		     =  wxID_DEFAULT,
        ID_MORE			     =  wxID_MORE,
        ID_SETUP		     =  wxID_SETUP,
        ID_RESET		     =  wxID_RESET,
        ID_CONTEXT_HELP		     =  wxID_CONTEXT_HELP,
        ID_YESTOALL		     =  wxID_YESTOALL,
        ID_NOTOALL		     =  wxID_NOTOALL,
        ID_ABORT		     =  wxID_ABORT,
        ID_RETRY		     =  wxID_RETRY,
        ID_IGNORE		     =  wxID_IGNORE,
        ID_ADD			     =  wxID_ADD,
        ID_REMOVE		     =  wxID_REMOVE,
        ID_UP			     =  wxID_UP,
        ID_DOWN			     =  wxID_DOWN,
        ID_HOME			     =  wxID_HOME,
        ID_REFRESH		     =  wxID_REFRESH,
        ID_STOP			     =  wxID_STOP,
        ID_INDEX		     =  wxID_INDEX,
        ID_BOLD			     =  wxID_BOLD,
        ID_ITALIC		     =  wxID_ITALIC,
        ID_JUSTIFY_CENTER	     =  wxID_JUSTIFY_CENTER,
        ID_JUSTIFY_FILL		     =  wxID_JUSTIFY_FILL,
        ID_JUSTIFY_RIGHT	     =  wxID_JUSTIFY_RIGHT,
        ID_JUSTIFY_LEFT		     =  wxID_JUSTIFY_LEFT,
        ID_UNDERLINE		     =  wxID_UNDERLINE,
        ID_INDENT		     =  wxID_INDENT,
        ID_UNINDENT		     =  wxID_UNINDENT,
        ID_ZOOM_100		     =  wxID_ZOOM_100,
        ID_ZOOM_FIT		     =  wxID_ZOOM_FIT,
        ID_ZOOM_IN		     =  wxID_ZOOM_IN,
        ID_ZOOM_OUT		     =  wxID_ZOOM_OUT,
        ID_UNDELETE		     =  wxID_UNDELETE,
        ID_REVERT_TO_SAVED	     =  wxID_REVERT_TO_SAVED,
        ID_CDROM		     =  wxID_CDROM,
        ID_CONVERT		     =  wxID_CONVERT,
        ID_EXECUTE		     =  wxID_EXECUTE,
        ID_FLOPPY		     =  wxID_FLOPPY,
        ID_HARDDISK		     =  wxID_HARDDISK,
        ID_BOTTOM		     =  wxID_BOTTOM,
        ID_FIRST		     =  wxID_FIRST,
        ID_LAST			     =  wxID_LAST,
        ID_TOP			     =  wxID_TOP,
        ID_INFO			     =  wxID_INFO,
        ID_JUMP_TO		     =  wxID_JUMP_TO,
        ID_NETWORK		     =  wxID_NETWORK,
        ID_SELECT_COLOR		     =  wxID_SELECT_COLOR,
        ID_SELECT_FONT		     =  wxID_SELECT_FONT,
        ID_SORT_ASCENDING	     =  wxID_SORT_ASCENDING,
        ID_SORT_DESCENDING	     =  wxID_SORT_DESCENDING,
        ID_SPELL_CHECK		     =  wxID_SPELL_CHECK,
        ID_STRIKETHROUGH	     =  wxID_STRIKETHROUGH,
        ID_SYSTEM_MENU		     =  wxID_SYSTEM_MENU,
        ID_CLOSE_FRAME		     =  wxID_CLOSE_FRAME,
        ID_MOVE_FRAME		     =  wxID_MOVE_FRAME,
        ID_RESIZE_FRAME		     =  wxID_RESIZE_FRAME,
        ID_MAXIMIZE_FRAME	     =  wxID_MAXIMIZE_FRAME,
        ID_ICONIZE_FRAME	     =  wxID_ICONIZE_FRAME,
        ID_RESTORE_FRAME	     =  wxID_RESTORE_FRAME,
        ID_MDI_WINDOW_FIRST	     =  wxID_MDI_WINDOW_FIRST,
        ID_MDI_WINDOW_CASCADE	     =  wxID_MDI_WINDOW_CASCADE,
        ID_MDI_WINDOW_TILE_HORZ	     =  wxID_MDI_WINDOW_TILE_HORZ,
        ID_MDI_WINDOW_TILE_VERT	     =  wxID_MDI_WINDOW_TILE_VERT,
        ID_MDI_WINDOW_ARRANGE_ICONS  =  wxID_MDI_WINDOW_ARRANGE_ICONS,
        ID_MDI_WINDOW_PREV	     =  wxID_MDI_WINDOW_PREV,
        ID_MDI_WINDOW_NEXT	     =  wxID_MDI_WINDOW_NEXT,
        ID_MDI_WINDOW_LAST	     =  wxID_MDI_WINDOW_LAST,
        ID_FILEDLGG		     =  wxID_FILEDLGG,
        ID_FILECTRL		     =  wxID_FILECTRL,
        ID_HIGHEST		     =  wxID_HIGHEST;

	export auto const &EVT_ACTIVATE = wxEVT_ACTIVATE;
	export auto const &EVT_ACTIVATE_APP = wxEVT_ACTIVATE_APP;
	export auto const &EVT_ANY = wxEVT_ANY;
	export auto const &EVT_AUX1_DCLICK = wxEVT_AUX1_DCLICK;
	export auto const &EVT_AUX1_DOWN = wxEVT_AUX1_DOWN;
	export auto const &EVT_AUX1_UP = wxEVT_AUX1_UP;
	export auto const &EVT_AUX2_DCLICK = wxEVT_AUX2_DCLICK;
	export auto const &EVT_AUX2_DOWN = wxEVT_AUX2_DOWN;
	export auto const &EVT_AUX2_UP = wxEVT_AUX2_UP;
	export auto const &EVT_BUTTON = wxEVT_BUTTON;
	export auto const &EVT_CHAR = wxEVT_CHAR;
	export auto const &EVT_CHAR_HOOK = wxEVT_CHAR_HOOK;
	export auto const &EVT_CHECKBOX = wxEVT_CHECKBOX;
	export auto const &EVT_CHECKLISTBOX = wxEVT_CHECKLISTBOX;
	export auto const &EVT_CHILD_FOCUS = wxEVT_CHILD_FOCUS;
	export auto const &EVT_CHOICE = wxEVT_CHOICE;
	export auto const &EVT_CLOSE_WINDOW = wxEVT_CLOSE_WINDOW;
	export auto const &EVT_COMBOBOX = wxEVT_COMBOBOX;
	export auto const &EVT_COMBOBOX_CLOSEUP = wxEVT_COMBOBOX_CLOSEUP;
	export auto const &EVT_COMBOBOX_DROPDOWN = wxEVT_COMBOBOX_DROPDOWN;
	export auto const &EVT_COMMAND_ENTER = wxEVT_COMMAND_ENTER;
	export auto const &EVT_COMMAND_KILL_FOCUS = wxEVT_COMMAND_KILL_FOCUS;
	export auto const &EVT_COMMAND_LEFT_CLICK = wxEVT_COMMAND_LEFT_CLICK;
	export auto const &EVT_COMMAND_LEFT_DCLICK = wxEVT_COMMAND_LEFT_DCLICK;
	export auto const &EVT_COMMAND_RIGHT_CLICK = wxEVT_COMMAND_RIGHT_CLICK;
	export auto const &EVT_COMMAND_RIGHT_DCLICK = wxEVT_COMMAND_RIGHT_DCLICK;
	export auto const &EVT_COMMAND_SET_FOCUS = wxEVT_COMMAND_SET_FOCUS;
	export auto const &EVT_CONTEXT_MENU = wxEVT_CONTEXT_MENU;
	export auto const &EVT_CREATE = wxEVT_CREATE;
	export auto const &EVT_DESTROY = wxEVT_DESTROY;
	export auto const &EVT_DETAILED_HELP = wxEVT_DETAILED_HELP;
	export auto const &EVT_DISPLAY_CHANGED = wxEVT_DISPLAY_CHANGED;
	export auto const &EVT_DPI_CHANGED = wxEVT_DPI_CHANGED;
	export auto const &EVT_DROP_FILES = wxEVT_DROP_FILES;
	export auto const &EVT_END_SESSION = wxEVT_END_SESSION;
	export auto const &EVT_ENTER_WINDOW = wxEVT_ENTER_WINDOW;
	export auto const &EVT_ERASE_BACKGROUND = wxEVT_ERASE_BACKGROUND;
	export auto const &EVT_FULLSCREEN = wxEVT_FULLSCREEN;
	export auto const &EVT_GESTURE_PAN = wxEVT_GESTURE_PAN;
	export auto const &EVT_GESTURE_ROTATE = wxEVT_GESTURE_ROTATE;
	export auto const &EVT_GESTURE_ZOOM = wxEVT_GESTURE_ZOOM;
	export auto const &EVT_HELP = wxEVT_HELP;
	export auto const &EVT_HIBERNATE = wxEVT_HIBERNATE;
	export auto const &EVT_HOTKEY = wxEVT_HOTKEY;
	export auto const &EVT_ICONIZE = wxEVT_ICONIZE;
	export auto const &EVT_IDLE = wxEVT_IDLE;
	export auto const &EVT_INIT_DIALOG = wxEVT_INIT_DIALOG;
	export auto const &EVT_JOY_BUTTON_DOWN = wxEVT_JOY_BUTTON_DOWN;
	export auto const &EVT_JOY_BUTTON_UP = wxEVT_JOY_BUTTON_UP;
	export auto const &EVT_JOY_MOVE = wxEVT_JOY_MOVE;
	export auto const &EVT_JOY_ZMOVE = wxEVT_JOY_ZMOVE;
	export auto const &EVT_KEY_DOWN = wxEVT_KEY_DOWN;
	export auto const &EVT_KEY_UP = wxEVT_KEY_UP;
	export auto const &EVT_KILL_FOCUS = wxEVT_KILL_FOCUS;
	export auto const &EVT_LEAVE_WINDOW = wxEVT_LEAVE_WINDOW;
	export auto const &EVT_LEFT_DCLICK = wxEVT_LEFT_DCLICK;
	export auto const &EVT_LEFT_DOWN = wxEVT_LEFT_DOWN;
	export auto const &EVT_LEFT_UP = wxEVT_LEFT_UP;
	export auto const &EVT_LISTBOX = wxEVT_LISTBOX;
	export auto const &EVT_LISTBOX_DCLICK = wxEVT_LISTBOX_DCLICK;
	export auto const &EVT_LONG_PRESS = wxEVT_LONG_PRESS;
	export auto const &EVT_MAGNIFY = wxEVT_MAGNIFY;
	export auto const &EVT_MAXIMIZE = wxEVT_MAXIMIZE;
	export auto const &EVT_MENU = wxEVT_MENU;
	export auto const &EVT_MENU_CLOSE = wxEVT_MENU_CLOSE;
	export auto const &EVT_MENU_HIGHLIGHT = wxEVT_MENU_HIGHLIGHT;
	export auto const &EVT_MENU_OPEN = wxEVT_MENU_OPEN;
	export auto const &EVT_MIDDLE_DCLICK = wxEVT_MIDDLE_DCLICK;
	export auto const &EVT_MIDDLE_DOWN = wxEVT_MIDDLE_DOWN;
	export auto const &EVT_MIDDLE_UP = wxEVT_MIDDLE_UP;
	export auto const &EVT_MOTION = wxEVT_MOTION;
	export auto const &EVT_MOUSE_CAPTURE_CHANGED = wxEVT_MOUSE_CAPTURE_CHANGED;
	export auto const &EVT_MOUSE_CAPTURE_LOST = wxEVT_MOUSE_CAPTURE_LOST;
	export auto const &EVT_MOUSEWHEEL = wxEVT_MOUSEWHEEL;
	export auto const &EVT_MOVE = wxEVT_MOVE;
	export auto const &EVT_MOVE_END = wxEVT_MOVE_END;
	export auto const &EVT_MOVE_START = wxEVT_MOVE_START;
	export auto const &EVT_MOVING = wxEVT_MOVING;
	export auto const &EVT_NAVIGATION_KEY = wxEVT_NAVIGATION_KEY;
	export auto const &EVT_NC_PAINT = wxEVT_NC_PAINT;
	export auto const &EVT_NULL = wxEVT_NULL;
	export auto const &EVT_PAINT = wxEVT_PAINT;
	export auto const &EVT_PALETTE_CHANGED = wxEVT_PALETTE_CHANGED;
	export auto const &EVT_PRESS_AND_TAP = wxEVT_PRESS_AND_TAP;
	export auto const &EVT_QUERY_END_SESSION = wxEVT_QUERY_END_SESSION;
	export auto const &EVT_QUERY_NEW_PALETTE = wxEVT_QUERY_NEW_PALETTE;
	export auto const &EVT_RADIOBOX = wxEVT_RADIOBOX;
	export auto const &EVT_RADIOBUTTON = wxEVT_RADIOBUTTON;
	export auto const &EVT_RIGHT_DCLICK = wxEVT_RIGHT_DCLICK;
	export auto const &EVT_RIGHT_DOWN = wxEVT_RIGHT_DOWN;
	export auto const &EVT_RIGHT_UP = wxEVT_RIGHT_UP;
	export auto const &EVT_SCROLL_BOTTOM = wxEVT_SCROLL_BOTTOM;
	export auto const &EVT_SCROLL_CHANGED = wxEVT_SCROLL_CHANGED;
	export auto const &EVT_SCROLL_LINEDOWN = wxEVT_SCROLL_LINEDOWN;
	export auto const &EVT_SCROLL_LINEUP = wxEVT_SCROLL_LINEUP;
	export auto const &EVT_SCROLL_PAGEDOWN = wxEVT_SCROLL_PAGEDOWN;
	export auto const &EVT_SCROLL_PAGEUP = wxEVT_SCROLL_PAGEUP;
	export auto const &EVT_SCROLL_THUMBRELEASE = wxEVT_SCROLL_THUMBRELEASE;
	export auto const &EVT_SCROLL_THUMBTRACK = wxEVT_SCROLL_THUMBTRACK;
	export auto const &EVT_SCROLL_TOP = wxEVT_SCROLL_TOP;
	export auto const &EVT_SCROLLBAR = wxEVT_SCROLLBAR;
	export auto const &EVT_SCROLLWIN_BOTTOM = wxEVT_SCROLLWIN_BOTTOM;
	export auto const &EVT_SCROLLWIN_LINEDOWN = wxEVT_SCROLLWIN_LINEDOWN;
	export auto const &EVT_SCROLLWIN_LINEUP = wxEVT_SCROLLWIN_LINEUP;
	export auto const &EVT_SCROLLWIN_PAGEDOWN = wxEVT_SCROLLWIN_PAGEDOWN;
	export auto const &EVT_SCROLLWIN_PAGEUP = wxEVT_SCROLLWIN_PAGEUP;
	export auto const &EVT_SCROLLWIN_THUMBRELEASE = wxEVT_SCROLLWIN_THUMBRELEASE;
	export auto const &EVT_SCROLLWIN_THUMBTRACK = wxEVT_SCROLLWIN_THUMBTRACK;
	export auto const &EVT_SCROLLWIN_TOP = wxEVT_SCROLLWIN_TOP;
	export auto const &EVT_SET_CURSOR = wxEVT_SET_CURSOR;
	export auto const &EVT_SET_FOCUS = wxEVT_SET_FOCUS;
	export auto const &EVT_SHOW = wxEVT_SHOW;
	export auto const &EVT_SIZE = wxEVT_SIZE;
	export auto const &EVT_SIZING = wxEVT_SIZING;
	export auto const &EVT_SLIDER = wxEVT_SLIDER;
	export auto const &EVT_SPIN = wxEVT_SPIN;
	export auto const &EVT_SPIN_DOWN = wxEVT_SPIN_DOWN;
	export auto const &EVT_SPIN_UP = wxEVT_SPIN_UP;
	export auto const &EVT_SYS_COLOUR_CHANGED = wxEVT_SYS_COLOUR_CHANGED;
	export auto const &EVT_TEXT_COPY = wxEVT_TEXT_COPY;
	export auto const &EVT_TEXT_CUT = wxEVT_TEXT_CUT;
	export auto const &EVT_TEXT_PASTE = wxEVT_TEXT_PASTE;
	export auto const &EVT_THREAD = wxEVT_THREAD;
	export auto const &EVT_TOOL = wxEVT_TOOL;
	export auto const &EVT_TOOL_DROPDOWN = wxEVT_TOOL_DROPDOWN;
	export auto const &EVT_TOOL_ENTER = wxEVT_TOOL_ENTER;
	export auto const &EVT_TOOL_RCLICKED = wxEVT_TOOL_RCLICKED;
	export auto const &EVT_TWO_FINGER_TAP = wxEVT_TWO_FINGER_TAP;
	export auto const &EVT_UPDATE_UI = wxEVT_UPDATE_UI;
	export auto const &EVT_VLBOX = wxEVT_VLBOX;
	export auto const &EVT_WINDOW_MODAL_DIALOG_CLOSED = wxEVT_WINDOW_MODAL_DIALOG_CLOSED;
}

#endif	    // #if defined __INTELLISENSE__


#endif	    // !defined ODBC_CLIENT_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
