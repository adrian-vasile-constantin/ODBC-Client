module;

#include <wx/list.h>
#include <wx/string.h>
#include <wx/secretstore.h>
#include <wx/object.h>
#include <wx/event.h>
#include <wx/app.h>

export module local.wx.Base;

namespace local
{
    namespace wx
    {
	export using List = wxList;
	export using Node = wxNode;
	export using SecretStore = wxSecretStore;
	export using SecretValue = wxSecretValue;
	export using SecretString = wxSecretString;
	export using String = wxString;
	export using Object = wxObject;
	export using Event = wxEvent;
	export using AppConsole = wxAppConsole;
	export using App = wxApp;
    }
}
