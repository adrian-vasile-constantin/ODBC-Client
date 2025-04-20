module;

#include <wx/grid.h>

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
}
