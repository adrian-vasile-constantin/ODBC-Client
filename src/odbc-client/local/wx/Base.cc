module;

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

export module local.wx.Base;

#if !defined __INTELLISENSE__
import std;

export import :DataStruct;
#endif

namespace local::wx
{
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
}
