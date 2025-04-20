module;

#include <wx/propgrid/propgriddefs.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/propgridiface.h>
#include <wx/propgrid/props.h>
#include <wx/propgrid/advprops.h>
#include <wx/propgrid/propgrid.h>

export module wx.Core:PropertyGrid;

namespace wx
{
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
	&PG_ATTR_DEFAULT_VALUE		    = wxPG_ATTR_DEFAULT_VALUE;

    export auto const
	&PG_ATTR_MIN			    = wxPG_ATTR_MIN;

    export auto const
	&PG_ATTR_MAX			    = wxPG_ATTR_MAX;

    export auto const
	&PG_ATTR_UNITS			    = wxPG_ATTR_UNITS;

    export auto const
	&PG_ATTR_HINT			    = wxPG_ATTR_HINT;

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
	&PG_LABEL			    = wxPG_LABEL;

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
