module;

#include "intellisense/odbc-client-headers.hh"

#include <locale>
#include <wx/app.h>	// macros: wxIMPLEMENT_APP

export module OdbcApp;

#if !defined MSVC_INTELLISENSE
import std;
import wx.Base;
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

using std::setlocale;

auto OdbcApp::OnInit() -> bool
{
    setlocale(LC_ALL, ".UTF8");

    OdbcFrame *frame { new OdbcFrame() };

    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(OdbcApp);
