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

#include <wx/position.h>
#include <wx/datetime.h>
#include <wx/string.h>
#include <wx/versioninfo.h>

#include <wx/dynarray.h>
#include <wx/arrstr.h>
#include <wx/list.h>
#include <wx/any.h>
#include <wx/secretstore.h>
#include <wx/object.h>
#include <wx/event.h>
#include <wx/app.h>
#include <wx/init.h>
#include <wx/cmdline.h>

#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/gdicmn.h>
#include <wx/defs.h>
#include <wx/event.h>

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

#include <wx/control.h>
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/bmpbuttn.h>
#include <wx/tglbtn.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>
#include <wx/textentry.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/combo.h>
#include <wx/listbox.h>
#include <wx/vlbox.h>
#include <wx/checklst.h>
#include <wx/listctrl.h>
#include <wx/rearrangectrl.h>
#include <wx/choice.h>
#include <wx/imaglist.h>
#include <wx/treectrl.h>
#include <wx/headerctrl.h>
#include <wx/treelist.h>
#include <wx/datectrl.h>
#include <wx/calctrl.h>
#include <wx/scrolbar.h>

#include <wx/filectrl.h>
#include <wx/dirctrl.h>
#include <wx/filepicker.h>

#include <wx/dataview.h>

#include <wx/sizer.h>
#include <wx/wrapsizer.h>
#include <wx/gbsizer.h>

#include <wx/toplevel.h>

#include <wx/display.h>
#include <wx/persist.h>

#include <wx/validate.h>
#include <wx/window.h>
#include <wx/nonownedwnd.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>

#include <wx/artprov.h>

#include <wx/grid.h>

#include <wx/propgrid/propgriddefs.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/propgridiface.h>
#include <wx/propgrid/props.h>
#include <wx/propgrid/advprops.h>
#include <wx/propgrid/propgrid.h>

// #include "intellisense/odbcxx_project_headers.hh"

#include "OdbcFrame.hh"

namespace wx
{
    export using DC	    = wxDC;
    export using WindowDC   = wxWindowDC;
    export using ClientDC   = wxClientDC;
    export using PaintDC    = wxPaintDC;


    export using Position	= wxPosition;
    export using DateTime	= wxDateTime;
    export using TimeSpan	= wxTimeSpan;
    export using String		= wxString;
    export using Char		= wxChar;
    export using UniChar	= wxUniChar;
    export using VersionInfo	= wxVersionInfo;

    export auto const
	&DefaultDateTime	= wxDefaultDateTime;

    export using List		    = wxList;
    export using Node		    = wxNode;

    export using ArrayShort	    = wxArrayShort;
    export using ArrayInt	    = wxArrayInt;
    export using ArrayLong	    = wxArrayLong;
    export using ArrayDouble	    = wxArrayDouble;
    export using ArrayPtrVoid	    = wxArrayPtrVoid;
    export using ArrayString	    = wxArrayString;
    export using SortedArrayString  = wxSortedArrayString;

    export using Any		    = wxAny;

    export using SecretStore	    = wxSecretStore;
    export using SecretValue	    = wxSecretValue;
    export using SecretString	    = wxSecretString;
    export using Object		    = wxObject;
    export using Event		    = wxEvent;
    export using AppConsole	    = wxAppConsole;
    export using App		    = wxApp;

    export using Initializer	    = wxInitializer;
    export using CmdLineParser	    = wxCmdLineParser;

    export template <typename... Args>
	inline auto EntryStart(Args &&... args)
    {
	using std::forward;

	return wxEntryStart(forward<Args>(args)...);
    }

    export inline auto EntryCleanup()
    {
	return wxEntryCleanup();
    }

    export template <typename... Args>
	inline auto Initialize(Args &&... args)
    {
	using std::forward;

	return wxInitialize(forward<Args>(args)...);
    }

    inline auto Uninitialize()
    {
	return wxUninitialize();
    }

    // inline auto GetApp()
    // {
    //     return wxGetApp();
    // }

    export constexpr auto const
	ANY_VALUE_BUFFER_SIZE = WX_ANY_VALUE_BUFFER_SIZE;

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

    export auto const SIZE_AUTO_WIDTH	 	  = wxSIZE_AUTO_WIDTH;
    export auto const SIZE_AUTO_HEIGHT         	  = wxSIZE_AUTO_HEIGHT;
    export auto const SIZE_AUTO                	  = wxSIZE_AUTO;
    export auto const SIZE_USE_EXISTING        	  = wxSIZE_USE_EXISTING;
    export auto const SIZE_ALLOW_MINUS_ONE     	  = wxSIZE_ALLOW_MINUS_ONE;
    export auto const SIZE_NO_ADJUSTMENTS      	  = wxSIZE_NO_ADJUSTMENTS;
    export auto const SIZE_FORCE               	  = wxSIZE_FORCE;
    export auto const SIZE_FORCE_EVENT         	  = wxSIZE_FORCE_EVENT;
    export auto const VSCROLL                  	  = wxVSCROLL;
    export auto const HSCROLL                  	  = wxHSCROLL;
    export auto const CAPTION                  	  = wxCAPTION;
    export auto const DOUBLE_BORDER            	  = wxDOUBLE_BORDER;
    export auto const SUNKEN_BORDER            	  = wxSUNKEN_BORDER;
    export auto const RAISED_BORDER            	  = wxRAISED_BORDER;
    export auto const BORDER                   	  = wxBORDER;
    export auto const SIMPLE_BORDER            	  = wxSIMPLE_BORDER;
    export auto const STATIC_BORDER            	  = wxSTATIC_BORDER;
    export auto const NO_BORDER                	  = wxNO_BORDER;
    export auto const ALWAYS_SHOW_SB           	  = wxALWAYS_SHOW_SB;
    export auto const CLIP_CHILDREN            	  = wxCLIP_CHILDREN;
    export auto const CLIP_SIBLINGS            	  = wxCLIP_SIBLINGS;
    export auto const TRANSPARENT_WINDOW       	  = wxTRANSPARENT_WINDOW;
    export auto const TAB_TRAVERSAL            	  = wxTAB_TRAVERSAL;
    export auto const WANTS_CHARS              	  = wxWANTS_CHARS;
    export auto const RETAINED                 	  = wxRETAINED;
    export auto const BACKINGSTORE             	  = wxBACKINGSTORE;
    export auto const POPUP_WINDOW             	  = wxPOPUP_WINDOW;
    export auto const FULL_REPAINT_ON_RESIZE   	  = wxFULL_REPAINT_ON_RESIZE;
    export auto const NO_FULL_REPAINT_ON_RESIZE	  = wxNO_FULL_REPAINT_ON_RESIZE;
    export auto const WINDOW_STYLE_MASK       	  = wxWINDOW_STYLE_MASK;
    export auto const WS_EX_BLOCK_EVENTS       	  = wxWS_EX_BLOCK_EVENTS;
    export auto const WS_EX_TRANSIENT          	  = wxWS_EX_TRANSIENT;
    export auto const WS_EX_THEMED_BACKGROUND  	  = wxWS_EX_THEMED_BACKGROUND;
    export auto const WS_EX_PROCESS_IDLE       	  = wxWS_EX_PROCESS_IDLE;
    export auto const WS_EX_PROCESS_UI_UPDATES 	  = wxWS_EX_PROCESS_UI_UPDATES;
    export auto const FRAME_EX_METAL           	  = wxFRAME_EX_METAL;
    export auto const DIALOG_EX_METAL          	  = wxDIALOG_EX_METAL;

#if defined WS_EX_CONTEXTHELP
# undef WS_EX_CONTEXTHELP
#endif

    export auto const WS_EX_CONTEXTHELP        	  = wxWS_EX_CONTEXTHELP;
    export auto const FRAME_EX_CONTEXTHELP     	  = wxFRAME_EX_CONTEXTHELP;
    export auto const DIALOG_EX_CONTEXTHELP    	  = wxDIALOG_EX_CONTEXTHELP;
    export auto const FRAME_DRAWER             	  = wxFRAME_DRAWER;
    export auto const FRAME_NO_WINDOW_MENU     	  = wxFRAME_NO_WINDOW_MENU;
    export auto const MB_DOCKABLE              	  = wxMB_DOCKABLE;
    export auto const MENU_TEAROFF             	  = wxMENU_TEAROFF;
    export auto const COLOURED                 	  = wxCOLOURED;
    export auto const FIXED_LENGTH             	  = wxFIXED_LENGTH;
    export auto const LB_SORT                  	  = wxLB_SORT;
    export auto const LB_SINGLE                	  = wxLB_SINGLE;
    export auto const LB_MULTIPLE              	  = wxLB_MULTIPLE;
    export auto const LB_EXTENDED              	  = wxLB_EXTENDED;
    export auto const LB_NEEDED_SB             	  = wxLB_NEEDED_SB;
    export auto const LB_OWNERDRAW             	  = wxLB_OWNERDRAW;
    export auto const LB_ALWAYS_SB             	  = wxLB_ALWAYS_SB;
    export auto const LB_NO_SB                 	  = wxLB_NO_SB;
    export auto const LB_HSCROLL               	  = wxLB_HSCROLL;
    export auto const LB_INT_HEIGHT            	  = wxLB_INT_HEIGHT;
    export auto const CB_SIMPLE                	  = wxCB_SIMPLE;
    export auto const CB_SORT                  	  = wxCB_SORT;
    export auto const CB_READONLY              	  = wxCB_READONLY;
    export auto const CB_DROPDOWN              	  = wxCB_DROPDOWN;
    export auto const RA_LEFTTORIGHT           	  = wxRA_LEFTTORIGHT;
    export auto const RA_TOPTOBOTTOM           	  = wxRA_TOPTOBOTTOM;
    export auto const RA_SPECIFY_COLS          	  = wxRA_SPECIFY_COLS;
    export auto const RA_SPECIFY_ROWS          	  = wxRA_SPECIFY_ROWS;
    export auto const RA_HORIZONTAL            	  = wxRA_HORIZONTAL;
    export auto const RA_VERTICAL              	  = wxRA_VERTICAL;
    export auto const RB_GROUP                 	  = wxRB_GROUP;
    export auto const RB_SINGLE                	  = wxRB_SINGLE;
    export auto const SB_HORIZONTAL            	  = wxSB_HORIZONTAL;
    export auto const SB_VERTICAL              	  = wxSB_VERTICAL;
    export auto const SP_HORIZONTAL            	  = wxSP_HORIZONTAL;
    export auto const SP_VERTICAL              	  = wxSP_VERTICAL;
    export auto const SP_ARROW_KEYS            	  = wxSP_ARROW_KEYS;
    export auto const SP_WRAP                  	  = wxSP_WRAP;
    export auto const TC_RIGHTJUSTIFY          	  = wxTC_RIGHTJUSTIFY;
    export auto const TC_FIXEDWIDTH            	  = wxTC_FIXEDWIDTH;
    export auto const TC_TOP                   	  = wxTC_TOP;
    export auto const TC_LEFT                  	  = wxTC_LEFT;
    export auto const TC_RIGHT                 	  = wxTC_RIGHT;
    export auto const TC_BOTTOM                	  = wxTC_BOTTOM;
    export auto const TC_MULTILINE             	  = wxTC_MULTILINE;
    export auto const TC_OWNERDRAW             	  = wxTC_OWNERDRAW;
    export auto const BI_EXPAND                	  = wxBI_EXPAND;
    export auto const LI_HORIZONTAL            	  = wxLI_HORIZONTAL;
    export auto const LI_VERTICAL              	  = wxLI_VERTICAL;
    export auto const YES                      	  = wxYES;
    export auto const OK                       	  = wxOK;
    export auto const NO                       	  = wxNO;
    export auto const YES_NO                   	  = wxYES_NO;
    export auto const CANCEL                   	  = wxCANCEL;
    export auto const APPLY                    	  = wxAPPLY;
    export auto const CLOSE                    	  = wxCLOSE;
    export auto const OK_DEFAULT               	  = wxOK_DEFAULT;
    export auto const YES_DEFAULT              	  = wxYES_DEFAULT;
    export auto const NO_DEFAULT               	  = wxNO_DEFAULT;
    export auto const CANCEL_DEFAULT           	  = wxCANCEL_DEFAULT;
    export auto const ICON_EXCLAMATION         	  = wxICON_EXCLAMATION;
    export auto const ICON_HAND                	  = wxICON_HAND;
    export auto const ICON_WARNING             	  = wxICON_WARNING;
    export auto const ICON_ERROR               	  = wxICON_ERROR;
    export auto const ICON_QUESTION            	  = wxICON_QUESTION;
    export auto const ICON_INFORMATION         	  = wxICON_INFORMATION;
    export auto const ICON_STOP                	  = wxICON_STOP;
    export auto const ICON_ASTERISK            	  = wxICON_ASTERISK;
    export auto const HELP                     	  = wxHELP;
    export auto const FORWARD                  	  = wxFORWARD;
    export auto const BACKWARD                 	  = wxBACKWARD;
    export auto const RESET                    	  = wxRESET;
    export auto const MORE                     	  = wxMORE;
    export auto const SETUP                    	  = wxSETUP;
    export auto const ICON_NONE                	  = wxICON_NONE;
    export auto const ICON_AUTH_NEEDED         	  = wxICON_AUTH_NEEDED;
    export auto const ICON_MASK                	  = wxICON_MASK;
    export auto const NOT_FOUND                	  = wxNOT_FOUND;
    export auto const PRINT_QUALITY_HIGH       	  = wxPRINT_QUALITY_HIGH;
    export auto const PRINT_QUALITY_MEDIUM     	  = wxPRINT_QUALITY_MEDIUM;
    export auto const PRINT_QUALITY_LOW        	  = wxPRINT_QUALITY_LOW;
    export auto const PRINT_QUALITY_DRAFT      	  = wxPRINT_QUALITY_DRAFT;

    export using Coord	    = wxCoord;
    export using StandardID = wxStandardID;

    export constexpr auto const
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

    export using EventType	 = wxEventType;

    export using CommandEvent	 = wxCommandEvent;
    export using CloseEvent	 = wxCloseEvent;
    export using PaintEvent	 = wxPaintEvent;
    export using MaximizeEvent	 = wxMaximizeEvent;
    export using FullScreenEvent = wxFullScreenEvent;
    export using EraseEvent	 = wxEraseEvent;
    export using FocusEvent	 = wxFocusEvent;
    export using SizeEvent	 = wxSizeEvent;

    export auto const &EVT_ACTIVATE                   = wxEVT_ACTIVATE;
    export auto const &EVT_ACTIVATE_APP               = wxEVT_ACTIVATE_APP;
    export auto const &EVT_ANY                        = wxEVT_ANY;
    export auto const &EVT_AUX1_DCLICK                = wxEVT_AUX1_DCLICK;
    export auto const &EVT_AUX1_DOWN                  = wxEVT_AUX1_DOWN;
    export auto const &EVT_AUX1_UP                    = wxEVT_AUX1_UP;
    export auto const &EVT_AUX2_DCLICK                = wxEVT_AUX2_DCLICK;
    export auto const &EVT_AUX2_DOWN                  = wxEVT_AUX2_DOWN;
    export auto const &EVT_AUX2_UP                    = wxEVT_AUX2_UP;
    export auto const &EVT_BUTTON                     = wxEVT_BUTTON;
    export auto const &EVT_CHAR                       = wxEVT_CHAR;
    export auto const &EVT_CHAR_HOOK                  = wxEVT_CHAR_HOOK;
    export auto const &EVT_CHECKBOX                   = wxEVT_CHECKBOX;
    export auto const &EVT_CHECKLISTBOX               = wxEVT_CHECKLISTBOX;
    export auto const &EVT_CHILD_FOCUS                = wxEVT_CHILD_FOCUS;
    export auto const &EVT_CHOICE                     = wxEVT_CHOICE;
    export auto const &EVT_CLOSE_WINDOW               = wxEVT_CLOSE_WINDOW;
    export auto const &EVT_COMBOBOX                   = wxEVT_COMBOBOX;
    export auto const &EVT_COMBOBOX_CLOSEUP           = wxEVT_COMBOBOX_CLOSEUP;
    export auto const &EVT_COMBOBOX_DROPDOWN          = wxEVT_COMBOBOX_DROPDOWN;
    export auto const &EVT_COMMAND_ENTER              = wxEVT_COMMAND_ENTER;
    export auto const &EVT_COMMAND_KILL_FOCUS         = wxEVT_COMMAND_KILL_FOCUS;
    export auto const &EVT_COMMAND_LEFT_CLICK         = wxEVT_COMMAND_LEFT_CLICK;
    export auto const &EVT_COMMAND_LEFT_DCLICK        = wxEVT_COMMAND_LEFT_DCLICK;
    export auto const &EVT_COMMAND_RIGHT_CLICK        = wxEVT_COMMAND_RIGHT_CLICK;
    export auto const &EVT_COMMAND_RIGHT_DCLICK       = wxEVT_COMMAND_RIGHT_DCLICK;
    export auto const &EVT_COMMAND_SET_FOCUS          = wxEVT_COMMAND_SET_FOCUS;
    export auto const &EVT_CONTEXT_MENU               = wxEVT_CONTEXT_MENU;
    export auto const &EVT_CREATE                     = wxEVT_CREATE;
    export auto const &EVT_DESTROY                    = wxEVT_DESTROY;
    export auto const &EVT_DETAILED_HELP              = wxEVT_DETAILED_HELP;
    export auto const &EVT_DISPLAY_CHANGED            = wxEVT_DISPLAY_CHANGED;
    export auto const &EVT_DPI_CHANGED                = wxEVT_DPI_CHANGED;
    export auto const &EVT_DROP_FILES                 = wxEVT_DROP_FILES;
    export auto const &EVT_END_SESSION                = wxEVT_END_SESSION;
    export auto const &EVT_ENTER_WINDOW               = wxEVT_ENTER_WINDOW;
    export auto const &EVT_ERASE_BACKGROUND           = wxEVT_ERASE_BACKGROUND;
    export auto const &EVT_FULLSCREEN                 = wxEVT_FULLSCREEN;
    export auto const &EVT_GESTURE_PAN                = wxEVT_GESTURE_PAN;
    export auto const &EVT_GESTURE_ROTATE             = wxEVT_GESTURE_ROTATE;
    export auto const &EVT_GESTURE_ZOOM               = wxEVT_GESTURE_ZOOM;
    export auto const &EVT_HELP                       = wxEVT_HELP;
    export auto const &EVT_HIBERNATE                  = wxEVT_HIBERNATE;
    export auto const &EVT_HOTKEY                     = wxEVT_HOTKEY;
    export auto const &EVT_ICONIZE                    = wxEVT_ICONIZE;
    export auto const &EVT_IDLE                       = wxEVT_IDLE;
    export auto const &EVT_INIT_DIALOG                = wxEVT_INIT_DIALOG;
    export auto const &EVT_JOY_BUTTON_DOWN            = wxEVT_JOY_BUTTON_DOWN;
    export auto const &EVT_JOY_BUTTON_UP              = wxEVT_JOY_BUTTON_UP;
    export auto const &EVT_JOY_MOVE                   = wxEVT_JOY_MOVE;
    export auto const &EVT_JOY_ZMOVE                  = wxEVT_JOY_ZMOVE;
    export auto const &EVT_KEY_DOWN                   = wxEVT_KEY_DOWN;
    export auto const &EVT_KEY_UP                     = wxEVT_KEY_UP;
    export auto const &EVT_KILL_FOCUS                 = wxEVT_KILL_FOCUS;
    export auto const &EVT_LEAVE_WINDOW               = wxEVT_LEAVE_WINDOW;
    export auto const &EVT_LEFT_DCLICK                = wxEVT_LEFT_DCLICK;
    export auto const &EVT_LEFT_DOWN                  = wxEVT_LEFT_DOWN;
    export auto const &EVT_LEFT_UP                    = wxEVT_LEFT_UP;
    export auto const &EVT_LISTBOX                    = wxEVT_LISTBOX;
    export auto const &EVT_LISTBOX_DCLICK             = wxEVT_LISTBOX_DCLICK;
    export auto const &EVT_LONG_PRESS                 = wxEVT_LONG_PRESS;
    export auto const &EVT_MAGNIFY                    = wxEVT_MAGNIFY;
    export auto const &EVT_MAXIMIZE                   = wxEVT_MAXIMIZE;
    export auto const &EVT_MENU                       = wxEVT_MENU;
    export auto const &EVT_MENU_CLOSE                 = wxEVT_MENU_CLOSE;
    export auto const &EVT_MENU_HIGHLIGHT             = wxEVT_MENU_HIGHLIGHT;
    export auto const &EVT_MENU_OPEN                  = wxEVT_MENU_OPEN;
    export auto const &EVT_MIDDLE_DCLICK              = wxEVT_MIDDLE_DCLICK;
    export auto const &EVT_MIDDLE_DOWN                = wxEVT_MIDDLE_DOWN;
    export auto const &EVT_MIDDLE_UP                  = wxEVT_MIDDLE_UP;
    export auto const &EVT_MOTION                     = wxEVT_MOTION;
    export auto const &EVT_MOUSE_CAPTURE_CHANGED      = wxEVT_MOUSE_CAPTURE_CHANGED;
    export auto const &EVT_MOUSE_CAPTURE_LOST         = wxEVT_MOUSE_CAPTURE_LOST;
    export auto const &EVT_MOUSEWHEEL                 = wxEVT_MOUSEWHEEL;
    export auto const &EVT_MOVE                       = wxEVT_MOVE;
    export auto const &EVT_MOVE_END                   = wxEVT_MOVE_END;
    export auto const &EVT_MOVE_START                 = wxEVT_MOVE_START;
    export auto const &EVT_MOVING                     = wxEVT_MOVING;
    export auto const &EVT_NAVIGATION_KEY             = wxEVT_NAVIGATION_KEY;
    export auto const &EVT_NC_PAINT                   = wxEVT_NC_PAINT;
    export auto const &EVT_NULL                       = wxEVT_NULL;
    export auto const &EVT_PAINT                      = wxEVT_PAINT;
    export auto const &EVT_PALETTE_CHANGED            = wxEVT_PALETTE_CHANGED;
    export auto const &EVT_PRESS_AND_TAP              = wxEVT_PRESS_AND_TAP;
    export auto const &EVT_QUERY_END_SESSION          = wxEVT_QUERY_END_SESSION;
    export auto const &EVT_QUERY_NEW_PALETTE          = wxEVT_QUERY_NEW_PALETTE;
    export auto const &EVT_RADIOBOX                   = wxEVT_RADIOBOX;
    export auto const &EVT_RADIOBUTTON                = wxEVT_RADIOBUTTON;
    export auto const &EVT_RIGHT_DCLICK               = wxEVT_RIGHT_DCLICK;
    export auto const &EVT_RIGHT_DOWN                 = wxEVT_RIGHT_DOWN;
    export auto const &EVT_RIGHT_UP                   = wxEVT_RIGHT_UP;
    export auto const &EVT_SCROLL_BOTTOM              = wxEVT_SCROLL_BOTTOM;
    export auto const &EVT_SCROLL_CHANGED             = wxEVT_SCROLL_CHANGED;
    export auto const &EVT_SCROLL_LINEDOWN            = wxEVT_SCROLL_LINEDOWN;
    export auto const &EVT_SCROLL_LINEUP              = wxEVT_SCROLL_LINEUP;
    export auto const &EVT_SCROLL_PAGEDOWN            = wxEVT_SCROLL_PAGEDOWN;
    export auto const &EVT_SCROLL_PAGEUP              = wxEVT_SCROLL_PAGEUP;
    export auto const &EVT_SCROLL_THUMBRELEASE        = wxEVT_SCROLL_THUMBRELEASE;
    export auto const &EVT_SCROLL_THUMBTRACK          = wxEVT_SCROLL_THUMBTRACK;
    export auto const &EVT_SCROLL_TOP                 = wxEVT_SCROLL_TOP;
    export auto const &EVT_SCROLLBAR                  = wxEVT_SCROLLBAR;
    export auto const &EVT_SCROLLWIN_BOTTOM           = wxEVT_SCROLLWIN_BOTTOM;
    export auto const &EVT_SCROLLWIN_LINEDOWN         = wxEVT_SCROLLWIN_LINEDOWN;
    export auto const &EVT_SCROLLWIN_LINEUP           = wxEVT_SCROLLWIN_LINEUP;
    export auto const &EVT_SCROLLWIN_PAGEDOWN         = wxEVT_SCROLLWIN_PAGEDOWN;
    export auto const &EVT_SCROLLWIN_PAGEUP           = wxEVT_SCROLLWIN_PAGEUP;
    export auto const &EVT_SCROLLWIN_THUMBRELEASE     = wxEVT_SCROLLWIN_THUMBRELEASE;
    export auto const &EVT_SCROLLWIN_THUMBTRACK       = wxEVT_SCROLLWIN_THUMBTRACK;
    export auto const &EVT_SCROLLWIN_TOP              = wxEVT_SCROLLWIN_TOP;
    export auto const &EVT_SET_CURSOR                 = wxEVT_SET_CURSOR;
    export auto const &EVT_SET_FOCUS                  = wxEVT_SET_FOCUS;
    export auto const &EVT_SHOW                       = wxEVT_SHOW;
    export auto const &EVT_SIZE                       = wxEVT_SIZE;
    export auto const &EVT_SIZING                     = wxEVT_SIZING;
    export auto const &EVT_SLIDER                     = wxEVT_SLIDER;
    export auto const &EVT_SPIN                       = wxEVT_SPIN;
    export auto const &EVT_SPIN_DOWN                  = wxEVT_SPIN_DOWN;
    export auto const &EVT_SPIN_UP                    = wxEVT_SPIN_UP;
    export auto const &EVT_SYS_COLOUR_CHANGED         = wxEVT_SYS_COLOUR_CHANGED;
    export auto const &EVT_TEXT_COPY                  = wxEVT_TEXT_COPY;
    export auto const &EVT_TEXT_CUT                   = wxEVT_TEXT_CUT;
    export auto const &EVT_TEXT_PASTE                 = wxEVT_TEXT_PASTE;
    export auto const &EVT_THREAD                     = wxEVT_THREAD;
    export auto const &EVT_TOOL                       = wxEVT_TOOL;
    export auto const &EVT_TOOL_DROPDOWN              = wxEVT_TOOL_DROPDOWN;
    export auto const &EVT_TOOL_ENTER                 = wxEVT_TOOL_ENTER;
    export auto const &EVT_TOOL_RCLICKED              = wxEVT_TOOL_RCLICKED;
    export auto const &EVT_TWO_FINGER_TAP             = wxEVT_TWO_FINGER_TAP;
    export auto const &EVT_UPDATE_UI                  = wxEVT_UPDATE_UI;
    export auto const &EVT_VLBOX                      = wxEVT_VLBOX;

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


#if defined BLACK_BRUSH
# undef BLACK_BRUSH
#endif


#if defined WHITE_BRUSH
# undef WHITE_BRUSH
#endif

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

#if defined BLACK_PEN
# undef BLACK_PEN
#endif


#if defined WHITE_PEN
# undef WHITE_PEN
#endif

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


    export using Control	    = wxControl;
    export using StaticText	    = wxStaticText;
    export using StaticBox	    = wxStaticBox;
    export using StaticBitmap	    = wxStaticBitmap;
    export using Button		    = wxButton;
    export using BitmapButton	    = wxBitmapButton;
    export using ToggleButton	    = wxToggleButton;
    export using RadioButton	    = wxRadioButton;
    export using RadioBox	    = wxRadioBox;
    export using TextEntry	    = wxTextEntry;
    export using TextCtrl	    = wxTextCtrl;
    export using ComboBox	    = wxComboBox;
    export using ComboCtrl	    = wxComboCtrl;
    export using ListBox	    = wxListBox;
    export using ListColumnFormat   = wxListColumnFormat;
    export using VListBox	    = wxVListBox;
    export using CheckListBox	    = wxCheckListBox;
    export using RearrangeList	    = wxRearrangeList;
    export using RearrangeCtrl	    = wxRearrangeCtrl;
    export using ListCtrl	    = wxListCtrl;
    export using ListItem	    = wxListItem;
    export using ListView	    = wxListView;
    export using ImageList	    = wxImageList;
    export using TreeCtrl	    = wxTreeCtrl;
    export using HeaderCtrl	    = wxHeaderCtrl;
    export using TreeListCtrl	    = wxTreeListCtrl;
    export using ScrollBar	    = wxScrollBar;
    export using Choice		    = wxChoice;
    export using DatePickerCtrl	    = wxDatePickerCtrl;
    export using DateEvent	    = wxDateEvent;
    export using CalendarCtrl	    = wxCalendarCtrl;
    export using CalendarEvent	    = wxCalendarEvent;
    export using FilePickerCtrl	    = wxFilePickerCtrl;
    export using DirPickerCtrl	    = wxDirPickerCtrl;
    export using FileDirPickerEvent = wxFileDirPickerEvent;
    export using DataViewListCtrl   = wxDataViewListCtrl;
    export using DataViewCtrl	    = wxDataViewCtrl;
    export using FileCtrl	    = wxFileCtrl;
    export using GenericFileCtrl    = wxGenericFileCtrl;
    export using GenericDirCtrl	    = wxGenericDirCtrl;

    export using ListEvent	    = wxListEvent;
    export using TreeEvent	    = wxTreeEvent;
    export using FileCtrlEvent	    = wxFileCtrlEvent;

    export constexpr auto const
	ST_NO_AUTORESIZE		    = wxST_NO_AUTORESIZE,
	ST_ELLIPSIZE_STAR		    = wxST_ELLIPSIZE_START,
	ST_ELLIPSIZE_MIDDL		    = wxST_ELLIPSIZE_MIDDLE,
	ST_ELLIPSIZE_EN			     = wxST_ELLIPSIZE_END;

    export constexpr auto const
	DP_SPIN				    = wxDP_SPIN,
	DP_DROPDOWN			    = wxDP_DROPDOWN,
	DP_DEFAULT			    = wxDP_DEFAULT,
	DP_ALLOWNONE			    = wxDP_ALLOWNONE,
	DP_SHOWCENTURY			    = wxDP_SHOWCENTURY;

    export constexpr auto const
	TR_EDIT_LABELS			    = wxTR_EDIT_LABELS,
	TR_NO_BUTTONS			    = wxTR_NO_BUTTONS,
	TR_HAS_BUTTONS			    = wxTR_HAS_BUTTONS,
	TR_TWIST_BUTTONS		    = wxTR_TWIST_BUTTONS,
	TR_NO_LINES			    = wxTR_NO_LINES,
	TR_FULL_ROW_HIGHLIGHT		    = wxTR_FULL_ROW_HIGHLIGHT,
	TR_LINES_AT_ROOT		    = wxTR_LINES_AT_ROOT,
    	TR_HIDE_ROOT			    = wxTR_HIDE_ROOT,
	TR_ROW_LINES			    = wxTR_ROW_LINES,
	TR_HAS_VARIABLE_ROW_HEIGHT	    = wxTR_HAS_VARIABLE_ROW_HEIGHT,
	TR_SINGLE			    = wxTR_SINGLE,
	TR_MULTIPLE			    = wxTR_MULTIPLE,
	TR_DEFAULT_STYLE		    = wxTR_DEFAULT_STYLE;

    export constexpr auto const
	CAL_SUNDAY_FIRST		    = wxCAL_SUNDAY_FIRST,
	CAL_MONDAY_FIRST		    = wxCAL_MONDAY_FIRST,
	CAL_SHOW_HOLIDAYS		    = wxCAL_SHOW_HOLIDAYS,
	CAL_NO_YEAR_CHANGE		    = wxCAL_NO_YEAR_CHANGE,
	CAL_NO_MONTH_CHANGE		    = wxCAL_NO_MONTH_CHANGE,
	CAL_SHOW_SURROUNDING_WEEKS	    = wxCAL_SHOW_SURROUNDING_WEEKS,
	CAL_SEQUENTIAL_MONTH_SELECTION	    = wxCAL_SEQUENTIAL_MONTH_SELECTION,
	CAL_SHOW_WEEK_NUMBERS		    = wxCAL_SHOW_WEEK_NUMBERS;

    export constexpr auto const
	FLP_DEFAULT_STYLE		    = wxFLP_DEFAULT_STYLE,
	FLP_USE_TEXTCTRL		    = wxFLP_USE_TEXTCTRL,
	FLP_OPEN			    = wxFLP_OPEN,
	FLP_SAVE			    = wxFLP_SAVE,
	FLP_OVERWRITE_PROMPT		    = wxFLP_OVERWRITE_PROMPT,
	FLP_FILE_MUST_EXIST		    = wxFLP_FILE_MUST_EXIST,
	FLP_CHANGE_DIR			    = wxFLP_CHANGE_DIR,
	FLP_SMALL			    = wxFLP_SMALL;

    export constexpr auto const
	DIRP_DEFAULT_STYLE		    = wxDIRP_DEFAULT_STYLE,
	DIRP_USE_TEXTCTRL		    = wxDIRP_USE_TEXTCTRL,
	DIRP_DIR_MUST_EXIST		    = wxDIRP_DIR_MUST_EXIST,
	DIRP_CHANGE_DIR			    = wxDIRP_CHANGE_DIR,
	DIRP_SMALL			    = wxDIRP_SMALL;

    export constexpr auto const
	DV_SINGLE			    = wxDV_SINGLE,
	DV_MULTIPLE			    = wxDV_MULTIPLE,
	DV_ROW_LINES			    = wxDV_ROW_LINES,
	DV_HORIZ_RULES			    = wxDV_HORIZ_RULES,
	DV_VERT_RULES			    = wxDV_VERT_RULES,
	DV_VARIABLE_LINE_HEIGHT		    = wxDV_VARIABLE_LINE_HEIGHT,
	DV_NO_HEADER			    = wxDV_NO_HEADER;

    export constexpr auto const
	FC_DEFAULT_STYLE		    = wxFC_DEFAULT_STYLE,
	FC_OPEN				    = wxFC_OPEN,
	FC_SAVE				    = wxFC_SAVE,
	FC_MULTIPLE			    = wxFC_MULTIPLE,
	FC_NOSHOWHIDDEN			    = wxFC_NOSHOWHIDDEN;

    export constexpr auto const
	DIRCTRL_DIR_ONLY		    = wxDIRCTRL_DIR_ONLY,
	DIRCTRL_3D_INTERNAL		    = wxDIRCTRL_3D_INTERNAL,
	DIRCTRL_SELECT_FIRST		    = wxDIRCTRL_SELECT_FIRST,
	DIRCTRL_SHOW_FILTERS		    = wxDIRCTRL_SHOW_FILTERS,
	DIRCTRL_EDIT_LABELS		    = wxDIRCTRL_EDIT_LABELS,
	DIRCTRL_MULTIPLE		    = wxDIRCTRL_MULTIPLE;

    export constexpr auto const
	LC_LIST				    = wxLC_LIST,
	LC_REPORT			    = wxLC_REPORT,
	LC_VIRTUAL			    = wxLC_VIRTUAL,
	LC_ICON				    = wxLC_ICON,
	LC_SMALL_ICON			    = wxLC_SMALL_ICON,
	LC_ALIGN_TOP			    = wxLC_ALIGN_TOP,
	LC_ALIGN_LEFT			    = wxLC_ALIGN_LEFT,
	LC_AUTOARRANGE			    = wxLC_AUTOARRANGE,
	LC_EDIT_LABELS			    = wxLC_EDIT_LABELS,
	LC_NO_HEADER			    = wxLC_NO_HEADER,
	LC_SINGLE_SEL			    = wxLC_SINGLE_SEL,
	LC_SORT_ASCENDING		    = wxLC_SORT_ASCENDING,
	LC_SORT_DESCENDING		    = wxLC_SORT_DESCENDING,
	LC_HRULES			    = wxLC_HRULES,
	LC_VRULES			    = wxLC_VRULES;

    export constexpr auto const
	LIST_FORMAT_LEFT		    = wxLIST_FORMAT_LEFT,
	LIST_FORMAT_RIGHT		    = wxLIST_FORMAT_RIGHT,
	LIST_FORMAT_CENTRE		    = wxLIST_FORMAT_CENTRE,
	LIST_FORMAT_CENTER		    = wxLIST_FORMAT_CENTER;

    export constexpr auto const
    	LIST_AUTOSIZE			    = wxLIST_AUTOSIZE,
	LIST_AUTOSIZE_USEHEADER		    = wxLIST_AUTOSIZE_USEHEADER;

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
    export using GridBagSizer		= wxGridBagSizer;
    export using GBSizerItem		= wxGBSizerItem;
    export using GBPosition		= wxGBPosition;
    export using GBSpan			= wxGBSpan;

    export auto const
	&DefaultSpan = wxDefaultSpan;

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
    export using ArtProvider	= wxArtProvider;

    export constexpr auto const
	ART_ERROR		= wxART_ERROR,
	ART_QUESTION		= wxART_QUESTION,
	ART_WARNING		= wxART_WARNING,
	ART_INFORMATION		= wxART_INFORMATION,
	ART_ADD_BOOKMARK	= wxART_ADD_BOOKMARK,
	ART_DEL_BOOKMARK	= wxART_DEL_BOOKMARK,
	ART_HELP_SIDE_PANEL	= wxART_HELP_SIDE_PANEL,
	ART_HELP_SETTINGS	= wxART_HELP_SETTINGS,
	ART_HELP_BOOK		= wxART_HELP_BOOK,
	ART_HELP_FOLDER		= wxART_HELP_FOLDER,
	ART_HELP_PAGE		= wxART_HELP_PAGE,
	ART_GO_BACK		= wxART_GO_BACK,
	ART_GO_FORWARD		= wxART_GO_FORWARD,
	ART_GO_UP		= wxART_GO_UP,
	ART_GO_DOWN		= wxART_GO_DOWN,
	ART_GO_TO_PARENT	= wxART_GO_TO_PARENT,
	ART_GO_HOME		= wxART_GO_HOME,
	ART_GOTO_FIRST		= wxART_GOTO_FIRST;

    export constexpr auto const
	ART_GOTO_LAST		= wxART_GOTO_LAST,
	ART_PRINT		= wxART_PRINT,
	ART_HELP		= wxART_HELP,
	ART_TIP			= wxART_TIP,
	ART_REPORT_VIEW		= wxART_REPORT_VIEW,
	ART_LIST_VIEW		= wxART_LIST_VIEW,
	ART_NEW_DIR		= wxART_NEW_DIR,
	ART_FOLDER		= wxART_FOLDER,
	ART_FOLDER_OPEN		= wxART_FOLDER_OPEN,
	ART_GO_DIR_UP		= wxART_GO_DIR_UP,
	ART_EXECUTABLE_FILE	= wxART_EXECUTABLE_FILE,
	ART_NORMAL_FILE		= wxART_NORMAL_FILE,
	ART_TICK_MARK		= wxART_TICK_MARK,
	ART_CROSS_MARK		= wxART_CROSS_MARK,
	ART_MISSING_IMAGE	= wxART_MISSING_IMAGE,
	ART_NEW			= wxART_NEW,
	ART_FILE_OPEN		= wxART_FILE_OPEN,
	ART_FILE_SAVE		= wxART_FILE_SAVE;

    export constexpr auto const
	ART_FILE_SAVE_AS	= wxART_FILE_SAVE_AS, 
	ART_DELETE		= wxART_DELETE, 
	ART_COPY		= wxART_COPY, 
	ART_CUT			= wxART_CUT, 
	ART_PASTE		= wxART_PASTE, 
	ART_UNDO		= wxART_UNDO, 
	ART_REDO		= wxART_REDO, 
	ART_PLUS		= wxART_PLUS, 
	ART_MINUS		= wxART_MINUS, 
	ART_CLOSE		= wxART_CLOSE, 
	ART_QUIT		= wxART_QUIT, 
	ART_FIND		= wxART_FIND, 
	ART_FIND_AND_REPLACE	= wxART_FIND_AND_REPLACE, 
	ART_FULL_SCREEN		= wxART_FULL_SCREEN, 
	ART_EDIT		= wxART_EDIT, 
	ART_HARDDISK		= wxART_HARDDISK, 
	ART_FLOPPY		= wxART_FLOPPY, 
	ART_CDROM		= wxART_CDROM, 
	ART_REMOVABLE		= wxART_REMOVABLE, 
	ART_WX_LOGO		= wxART_WX_LOGO;

    export constexpr auto const
	ART_TOOLBAR		= wxART_TOOLBAR,
	ART_MENU		= wxART_MENU,
	ART_BUTTON		= wxART_BUTTON,
	ART_FRAME_ICON		= wxART_FRAME_ICON,
	ART_CMN_DIALOG		= wxART_CMN_DIALOG,
	ART_HELP_BROWSER	= wxART_HELP_BROWSER,
	ART_MESSAGE_BOX		= wxART_MESSAGE_BOX,
	ART_OTHER		= wxART_OTHER;

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

    export auto const
	&PanelNameStr = wxPanelNameStr;

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

    export using Grid			 = wxGrid;
    export using GridCellRenderer	 = wxGridCellRenderer;
    export using GridCellBoolRenderer	 = wxGridCellBoolRenderer;
    export using GridCellFloatRenderer	 = wxGridCellFloatRenderer;
    export using GridCellNumberRenderer  = wxGridCellNumberRenderer;
    export using GridCellStringRenderer  = wxGridCellStringRenderer;
    export using GridCellAutoWrapStringRenderer = wxGridCellAutoWrapStringRenderer;
    export using GridCellDateRenderer	 = wxGridCellDateRenderer;
    export using GridCellDatTimeRenderer = wxGridCellDateTimeRenderer;

    export using GridCellEditor		 = wxGridCellEditor;
    export using GridCellBoolEditor	 = wxGridCellBoolEditor;
    export using GridCellChoiceEditor	 = wxGridCellChoiceEditor;
    export using GridCellEnumEditor	 = wxGridCellEnumEditor;
    export using GridCellFloatEditor	 = wxGridCellFloatEditor;
    export using GridCellNumberEditor	 = wxGridCellNumberEditor;
    export using GridCellTextEditor	 = wxGridCellTextEditor;
    export using GridCellDateEditor	 = wxGridCellDateEditor;

    export using GridFitMode		 = wxGridFitMode;
    export using GridTableBase		 = wxGridTableBase;
    export using GridCellAttr		 = wxGridCellAttr;

    export using GridEvent		 = wxGridEvent;
    export using GridSizeEvent		 = wxGridSizeEvent;
    export using GridRangeSelectEvent	 = wxGridRangeSelectEvent;
    export using GridEditorCreatedEvent  = wxGridEditorCreatedEvent;
    export using GridUpdateLocker	 = wxGridUpdateLocker;

    export using GridSelection		 = wxGridSelection;

    export constexpr auto const
	GridSelectCells			 = wxGridSelectCells,
	GridSelectRows			 = wxGridSelectRows,
	GridSelectColumns		 = wxGridSelectColumns,
	GridSelectRowsOrColumns		 = wxGridSelectRowsOrColumns,
	GridSelectNone			 = wxGridSelectNone;

    export using PropertyGridInterfaace	 = wxPropertyGridInterface;
    export using PropertyGrid		 = wxPropertyGrid;
    export using PropertyGridPageState	 = wxPropertyGridPageState;
    export using PropertyGridManager	 = wxPropertyGridManager;

    export using PropertyGridEvent	 = wxPropertyGridEvent;
    // export using PropertyGridValidationInfo = wxPropertyGridValidationInfo;
    export using PropertyGridPopulator	 = wxPropertyGridPopulator;

    export using PG_WINDOW_STYLES	 = wxPG_WINDOW_STYLES;

    export constexpr auto const
	PG_AUTO_SORT			 = wxPG_AUTO_SORT,
	PG_HIDE_CATEGORIES		 = wxPG_HIDE_CATEGORIES,
	PG_ALPHABETIC_MODE		 = wxPG_ALPHABETIC_MODE,
	PG_BOLD_MODIFIED		 = wxPG_BOLD_MODIFIED,
	PG_SPLITTER_AUTO_CENTER		 = wxPG_SPLITTER_AUTO_CENTER,
	PG_TOOLTIPS			 = wxPG_TOOLTIPS,
	PG_HIDE_MARGIN			 = wxPG_HIDE_MARGIN,
	PG_STATIC_SPLITTER		 = wxPG_STATIC_SPLITTER,
	PG_STATIC_LAYOUT		 = wxPG_STATIC_LAYOUT,
	PG_LIMITED_EDITING		 = wxPG_LIMITED_EDITING,
	PG_TOOLBAR			 = wxPG_TOOLBAR,
	PG_DESCRIPTION			 = wxPG_DESCRIPTION,
	PG_NO_INTERNAL_BORDER		 = wxPG_NO_INTERNAL_BORDER,
	PG_WINDOW_STYLE_MASK		 = wxPG_WINDOW_STYLE_MASK;

    export using PG_EX_WINDOW_STYLES	 = wxPG_EX_WINDOW_STYLES;

    export constexpr auto const
	PG_EX_INIT_NOCAT		    = wxPG_EX_INIT_NOCAT,
	PG_EX_NO_FLAT_TOOLBAR		    = wxPG_EX_NO_FLAT_TOOLBAR,
	PG_EX_MODE_BUTTONS		    = wxPG_EX_MODE_BUTTONS,
	PG_EX_HELP_AS_TOOLTIPS		    = wxPG_EX_HELP_AS_TOOLTIPS,
	PG_EX_NATIVE_DOUBLE_BUFFERING	    = wxPG_EX_NATIVE_DOUBLE_BUFFERING,
	PG_EX_AUTO_UNSPECIFIED_VALUES	    = wxPG_EX_AUTO_UNSPECIFIED_VALUES,
	PG_EX_WRITEONLY_BUILTIN_ATTRIBUTES  = wxPG_EX_WRITEONLY_BUILTIN_ATTRIBUTES,
	PG_EX_HIDE_PAGE_BUTTONS		    = wxPG_EX_HIDE_PAGE_BUTTONS,
	PG_EX_MULTIPLE_SELECTION	    = wxPG_EX_MULTIPLE_SELECTION,
	PG_EX_ENABLE_TLP_TRACKING	    = wxPG_EX_ENABLE_TLP_TRACKING,
	PG_EX_NO_TOOLBAR_DIVIDER	    = wxPG_EX_NO_TOOLBAR_DIVIDER,
	PG_EX_TOOLBAR_SEPARATOR		    = wxPG_EX_TOOLBAR_SEPARATOR,
	PG_EX_ALWAYS_ALLOW_FOCUS	    = wxPG_EX_ALWAYS_ALLOW_FOCUS,
	PG_EX_WINDOW_PG_STYLE_MASK	    = wxPG_EX_WINDOW_PG_STYLE_MASK,
	PG_EX_WINDOW_PGMAN_STYLE_MASK	    = wxPG_EX_WINDOW_PGMAN_STYLE_MASK;

    export constexpr auto const
	PG_EX_WINDOW_STYLE_MASK		    = wxPG_EX_WINDOW_STYLE_MASKK;
    export using PropertyGridInterfaace	 = wxPropertyGridInterface;
    export using PropertyGrid		 = wxPropertyGrid;
    export using PropertyGridPageState	 = wxPropertyGridPageState;
    export using PropertyGridManager	 = wxPropertyGridManager;
    export using PGProgArg		 = wxPGPropArg;

    export using BoolProperty		 = wxBoolProperty;
    export using IntProperty		 = wxIntProperty;
    export using FloagProperty		 = wxFloatProperty;
    export using StringProperty		 = wxStringProperty;
    export using LongStringProperty	 = wxLongStringProperty;
    export using ArrayStringProperty	 = wxArrayStringProperty;
    export using EnumProperty		 = wxEnumProperty;
    export using EditEnumProperty	 = wxEditEnumProperty;
    export using CursorProperty		 = wxCursorProperty;
    export using SystemColourProperty	 = wxSystemColourProperty;
    export using ColourProperty		 = wxColourProperty;
    export using DirProperty		 = wxDirProperty;
    export using FileProperty		 = wxFileProperty;

    export using PropertyGridEvent	 = wxPropertyGridEvent;
    // export using PropertyGridValidationInfo = wxPropertyGridValidationInfo;
    export using PropertyGridPopulator	 = wxPropertyGridPopulator;

    export using PG_WINDOW_STYLES	 = wxPG_WINDOW_STYLES;

    export constexpr auto const
	PG_AUTO_SORT			 = wxPG_AUTO_SORT,
	PG_HIDE_CATEGORIES		 = wxPG_HIDE_CATEGORIES,
	PG_ALPHABETIC_MODE		 = wxPG_ALPHABETIC_MODE,
	PG_BOLD_MODIFIED		 = wxPG_BOLD_MODIFIED,
	PG_SPLITTER_AUTO_CENTER		 = wxPG_SPLITTER_AUTO_CENTER,
	PG_TOOLTIPS			 = wxPG_TOOLTIPS,
	PG_HIDE_MARGIN			 = wxPG_HIDE_MARGIN,
	PG_STATIC_SPLITTER		 = wxPG_STATIC_SPLITTER,
	PG_STATIC_LAYOUT		 = wxPG_STATIC_LAYOUT,
	PG_LIMITED_EDITING		 = wxPG_LIMITED_EDITING,
	PG_TOOLBAR			 = wxPG_TOOLBAR,
	PG_DESCRIPTION			 = wxPG_DESCRIPTION,
	PG_NO_INTERNAL_BORDER		 = wxPG_NO_INTERNAL_BORDER,
	PG_WINDOW_STYLE_MASK		 = wxPG_WINDOW_STYLE_MASK;

    export constexpr auto const
	PG_DEFAULT_STYLE		 = wxPG_DEFAULT_STYLE;

    export using PG_EX_WINDOW_STYLES	 = wxPG_EX_WINDOW_STYLES;

    export constexpr auto const
	PG_EX_INIT_NOCAT		    = wxPG_EX_INIT_NOCAT,
	PG_EX_NO_FLAT_TOOLBAR		    = wxPG_EX_NO_FLAT_TOOLBAR,
	PG_EX_MODE_BUTTONS		    = wxPG_EX_MODE_BUTTONS,
	PG_EX_HELP_AS_TOOLTIPS		    = wxPG_EX_HELP_AS_TOOLTIPS,
	PG_EX_NATIVE_DOUBLE_BUFFERING	    = wxPG_EX_NATIVE_DOUBLE_BUFFERING,
	PG_EX_AUTO_UNSPECIFIED_VALUES	    = wxPG_EX_AUTO_UNSPECIFIED_VALUES,
	PG_EX_WRITEONLY_BUILTIN_ATTRIBUTES  = wxPG_EX_WRITEONLY_BUILTIN_ATTRIBUTES,
	PG_EX_HIDE_PAGE_BUTTONS		    = wxPG_EX_HIDE_PAGE_BUTTONS,
	PG_EX_MULTIPLE_SELECTION	    = wxPG_EX_MULTIPLE_SELECTION,
	PG_EX_ENABLE_TLP_TRACKING	    = wxPG_EX_ENABLE_TLP_TRACKING,
	PG_EX_NO_TOOLBAR_DIVIDER	    = wxPG_EX_NO_TOOLBAR_DIVIDER,
	PG_EX_TOOLBAR_SEPARATOR		    = wxPG_EX_TOOLBAR_SEPARATOR,
	PG_EX_ALWAYS_ALLOW_FOCUS	    = wxPG_EX_ALWAYS_ALLOW_FOCUS,
	PG_EX_WINDOW_PG_STYLE_MASK	    = wxPG_EX_WINDOW_PG_STYLE_MASK,
	PG_EX_WINDOW_PGMAN_STYLE_MASK	    = wxPG_EX_WINDOW_PGMAN_STYLE_MASK,
	PG_EX_WINDOW_STYLE_MASK		    = wxPG_EX_WINDOW_STYLE_MASK;

    export constexpr auto const
	PGMAN_DEFAULT_STYLE		    = wxPGMAN_DEFAULT_STYLE;

    export using PGVFBFlags		    = wxPGVFBFlags;

    export constexpr auto const
	PG_PROP_MAX			    = wxPG_PROP_MAX;

    export constexpr auto const
	PG_PROP_PARENTAL_FLAGS		    = wxPG_PROP_PARENTAL_FLAGS;

    export constexpr auto const
	PG_STRING_STORED_FALGS		    = wxPG_STRING_STORED_FLAGS;

    using PGPropertyFlags		    = wxPGPropertyFlags;

    export constexpr auto const
	PG_PROP_MODIFIED		    = wxPG_PROP_MODIFIED,
	PG_PROP_DISABLED		    = wxPG_PROP_DISABLED,
	PG_PROP_HIDDEN			    = wxPG_PROP_HIDDEN,
	PG_PROP_CUSTOMIMAGE		    = wxPG_PROP_CUSTOMIMAGE,
	PG_PROP_NOEDITOR		    = wxPG_PROP_NOEDITOR,
	PG_PROP_COLLAPSED		    = wxPG_PROP_COLLAPSED,
	PG_PROP_INVALID_VALUE		    = wxPG_PROP_INVALID_VALUE,
	PG_PROP_WAS_MODIFIED		    = wxPG_PROP_WAS_MODIFIED,
	PG_PROP_AGGREGATE		    = wxPG_PROP_AGGREGATE,
	PG_PROP_CHILDREN_ARE_COPIES	    = wxPG_PROP_CHILDREN_ARE_COPIES,
	PG_PROP_PROPERTY		    = wxPG_PROP_PROPERTY,
	PG_PROP_CATEGORY		    = wxPG_PROP_CATEGORY,
	PG_PROP_MISC_PARENT		    = wxPG_PROP_MISC_PARENT,
	PG_PROP_READONLY		    = wxPG_PROP_READONLY,
	PG_PROP_COMPOSED_VALUE		    = wxPG_PROP_COMPOSED_VALUE,
	PG_PROP_USES_COMMON_VALUE	    = wxPG_PROP_USES_COMMON_VALUE,
	PG_PROP_AUTO_UNSPECIFIED	    = wxPG_PROP_AUTO_UNSPECIFIED,
	PG_PROP_CLASS_SPECIFIC_1	    = wxPG_PROP_CLASS_SPECIFIC_1,
	PG_PROP_CLASS_SPECIFIC_2	    = wxPG_PROP_CLASS_SPECIFIC_2,
	PG_PROP_BEING_DELETED		    = wxPG_PROP_BEING_DELETED;

    using PGPaintData			    = wxPGPaintData;
    using PGPProperty			    = wxPGProperty;
    using PGCellRenderer		    = wxPGCellRenderer;
    using PGDefaultRenderer		    = wxPGDefaultRenderer;
    using PGCellData			    = wxPGCellData;
    using PGCell			    = wxPGCell;
    using PGAttributeStorage		    = wxPGAttributeStorage;
    using PGChoiceEntry			    = wxPGChoiceEntry;
    using PGChoiceesDtata		    = wxPGChoicesData;
    using PGChoices			    = wxPGChoices;
    using PGRootProperty		    = wxPGRootProperty;
    using wxPropertyCategory		    = wxPropertyCategory;

    export constexpr auto const
	NullProperty			    = wxNullProperty;

    export constexpr auto const
	PGChoicesEmtpyData		    = wxPGChoicesEmptyData;

    export auto const
	PG_ATTR_DEFAULT_VALUE		    = wxPG_ATTR_DEFAULT_VALUE;

    export auto const
	PG_ATTR_MIN			    = wxPG_ATTR_MIN;

    export auto const
	PG_ATTR_MAX			    = wxPG_ATTR_MAX;

    export auto const
	PG_ATTR_UNITS			    = wxPG_ATTR_UNITS;

    export auto const
	PG_ATTR_HINT			    = wxPG_ATTR_HINT;

    export constexpr auto const
	PG_ATTR_AUTOCOMPLETE		    = wxPG_ATTR_AUTOCOMPLETE;

    export constexpr auto const
	PG_BOOL_USE_CHECKBOX		    = wxPG_BOOL_USE_CHECKBOX;

    export constexpr auto const
	PG_BOOL_USE_DOUBLE_CLICK_CYCLING    = wxPG_BOOL_USE_DOUBLE_CLICK_CYCLING;

    export constexpr auto const
	PG_FLOAT_PRECISION		    = wxPG_FLOAT_PRECISION;

    export constexpr auto const
	PG_STRING_PASSWORD		    = wxPG_STRING_PASSWORD;

    export constexpr auto const
	PG_UINT_BASE			    = wxPG_UINT_BASE;

    export constexpr auto const
	PG_UINT_PREFIX			    = wxPG_UINT_PREFIX;

    export constexpr auto const
	PG_DIALOG_TITLE			    = wxPG_DIALOG_TITLE;

    export constexpr auto const
	PG_FILE_WILDCARD		    = wxPG_FILE_WILDCARD;

    export constexpr auto const
	PG_FILE_SHOW_FULL_PATH		    = wxPG_FILE_SHOW_FULL_PATH;

    export constexpr auto const
	PG_FILE_SHOW_RELATIVE_PATH	    = wxPG_FILE_SHOW_RELATIVE_PATH;

    export constexpr auto const
	PG_FILE_INITIAL_PATH		    = wxPG_FILE_INITIAL_PATH;

    export constexpr auto const
	PG_FILE_DIALOG_STYLE		    = wxPG_FILE_DIALOG_STYLE;

    export constexpr auto const
	PG_ARRAY_DELIMITER		    = wxPG_ARRAY_DELIMITER;

    export constexpr auto const
	PG_DATE_FORMAT			    = wxPG_DATE_FORMAT;

    export constexpr auto const
	PG_DATE_PICKER_STYLE		    = wxPG_DATE_PICKER_STYLE;

    export constexpr auto const
	PG_ATTR_SPINCTRL_STEP		    = wxPG_ATTR_SPINCTRL_STEP;

    export constexpr auto const
	PG_ATTR_SPINCTRL_WRAP		    = wxPG_ATTR_SPINCTRL_WRAP;

    export constexpr auto const
	PG_ATTR_SPINCTRL_MOTION		    = wxPG_ATTR_SPINCTRL_MOTION;

    export constexpr auto const
	PG_ATTR_MULTICHOICE_USERSTRINGMODE  = wxPG_ATTR_MULTICHOICE_USERSTRINGMODE;

    export constexpr auto const
	PG_COLOUR_ALLOW_CUSTOM		    = wxPG_COLOUR_ALLOW_CUSTOM;

    export constexpr auto const
	PG_COLOUR_HAS_ALPHA		    = wxPG_COLOUR_HAS_ALPHA;

    export constexpr auto const
	PG_STRING_STORED_FLAGS		    = wxPG_STRING_STORED_FLAGS;

    export auto const
	PG_LABEL			    = wxPG_LABEL;

    export constexpr auto const
	PG_LABEL_STRING			    = wxPG_LABEL_STRING;

    export auto const
	PG_NULL_BITMAP			    = wxPG_NULL_BITMAP;

    export auto const
	PG_COLOUR_BLACK			    = wxPG_COLOUR_BLACK;

    export auto const
	PG_DEFAULT_IMAGE_SIZE		    = wxPG_DEFAULT_IMAGE_SIZE;

    export constexpr auto const
	PG_INVALID_VALUE		    = wxPG_INVALID_VALUE;

    export constexpr auto const
	PG_BASE_OCT			    = wxPG_BASE_OCT,
	PG_BASE_DEC			    = wxPG_BASE_DEC,
	PG_BASE_HEX			    = wxPG_BASE_HEX,
	PG_BASE_HEXL			    = wxPG_BASE_HEXL,
	PG_PREFIX_NONE			    = wxPG_PREFIX_NONE,
	PG_PREFIX_0x			    = wxPG_PREFIX_0x,
	PG_PREFIX_DOLLAR_SIGN		    = wxPG_PREFIX_DOLLAR_SIGN;

    export using PGSortCallback		    = wxPGSortCallback;
    export using PG_GETPROPERTYVALUES_FLAGS = wxPG_PROPERTYVALUES_FLAGS;
    export using PG_MISC_ARG_FLAGS	    = wxPG_MISC_ARG_FLAGS;
    export using PG_SETVALUE_FALGS	    = wxPG_SETVALUE_FLAGS;
}

#endif	    // #if defined __INTELLISENSE__

#endif	    // !defined ODBC_CLIENT_INTELLISENSE_PROJECT_HEADERS_HH_INCLUDED
