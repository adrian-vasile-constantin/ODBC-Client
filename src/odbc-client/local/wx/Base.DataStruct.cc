module;

#include <wx/position.h>
#include <wx/datetime.h>
#include <wx/string.h>
#include <wx/versioninfo.h>

export module local.wx.Base:DataStruct;

namespace local::wx
{
    export using Position	= wxPosition;
    export using DateTime	= wxDateTime;
    export using TimeSpan	= wxTimeSpan;
    export using String		= wxString;
    export using Char		= wxChar;
    export using UniChar	= wxUniChar;
    export using VersionInfo	= wxVersionInfo;

    export auto const
	&DefaultDateTime	= wxDefaultDateTime;
}
