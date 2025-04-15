module;

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

export module wx.Core:Controls;

namespace wx
{
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
	ST_ELLIPSIZE_ENd		    = wxST_ELLIPSIZE_END;

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
}
