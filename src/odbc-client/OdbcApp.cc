module;

#include "intellisense/odbc-client-headers.hh"

#include <wx/app.h>	// macros: wxIMPLEMENT_APP

export module OdbcApp;

#if !defined MSVC_INTELLISENSE
import local.wx.Base;

namespace wx = local::wx;

#endif

class OdbcApp: public wx::App
{
    public:
	virtual auto OnInit() -> bool override;
};

module :private;

#if !defined MSVC_INTELLISENSE
import OdbcFrame;
#endif

auto OdbcApp::OnInit() -> bool
{
    OdbcFrame *frame { new OdbcFrame() };

    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(OdbcApp);
