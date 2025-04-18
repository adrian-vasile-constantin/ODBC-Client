module;

#include <wx/grid.h>
#include <wx/propgrid/propgridiface.h>
#include <wx/propgrid/propgrid.h>

export module wx.Core:Grid;

namespace wx
{
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

    export using GridSelectionModes	 = wxGrid::wxGridSelectionModes;

    export constexpr auto const
	GridSelectCells			 = wxGrid::wxGridSelectCells,
	GridSelectRows			 = wxGrid::wxGridSelectRows,
	GridSelectColumns		 = wxGrid::wxGridSelectColumns,
	GridSelectRowsOrColumns		 = wxGrid::wxGridSelectRowsOrColumns,
	GridSelectNone			 = wxGrid::wxGridSelectNone;

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
	PG_EX_WINDOW_PGMAN_STYLE_MASK	    = wxPG_EX_WINDOW_PGMAN_STYLE_MASK,
	PG_EX_WINDOW_STYLE_MASK		    = wxPG_EX_WINDOW_STYLE_MASK;
}
