module;

#include <wx/app.h>

export module OdbcApp;

class OdbcApp: public wxApp
{
    public:
	virtual auto OnInit() -> bool override;
};

module :private;

import OdbcFrame;

auto OdbcApp::OnInit() -> bool
{
    OdbcFrame *frame { new OdbcFrame() };

    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(OdbcApp);
