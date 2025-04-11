module;

#include <wx/defs.h>
#include <wx/event.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>

#if defined __INTELLISENSE__

#define MSVC_INTELLISENSE 1

#include <memory>

#endif

export module OdbcFrame;

export class OdbcFrame: public wxFrame
{
public:
    OdbcFrame();

private:
    auto OnConnect(wxCommandEvent &event) -> void;
    auto OnExit(wxCommandEvent &event) -> void;
    auto OnAbout(wxCommandEvent &event) -> void;
};

module :private;

#if !defined MSVC_INTELLISENSE

import std;

#endif

using std::unique_ptr;

enum
{
    ID_Connect = 1
};

OdbcFrame::OdbcFrame()
    : wxFrame(nullptr, wxID_ANY, "ODBC Client")
{
    auto menuFile = unique_ptr<wxMenu> { new wxMenu() };

    menuFile->Append(ID_Connect, "Connect...", "Connect to selected ODBC driver or Data Source Name");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto menuHelp = unique_ptr<wxMenu> { new wxMenu() };
    menuHelp->Append(wxID_ABOUT);

    auto menuBar = unique_ptr<wxMenuBar> { new wxMenuBar() };
    menuBar->Append(menuFile.release(), "&ODBC");
    menuBar->Append(menuHelp.release(), "&Help");

    SetMenuBar(menuBar.release());

    CreateStatusBar();
    SetStatusText("Connect to ODBC data source");

    Bind(wxEVT_MENU, &OdbcFrame::OnConnect, this, ID_Connect);
    Bind(wxEVT_MENU, &OdbcFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &OdbcFrame::OnAbout, this, wxID_ABOUT);
}

auto OdbcFrame::OnExit(wxCommandEvent &event) -> void
{
    Close(true);
}

auto OdbcFrame::OnConnect(wxCommandEvent &event) -> void
{
    wxMessageBox("ODBC Connect", "ODBC Client", wxOK | wxICON_INFORMATION, this);
}

auto OdbcFrame::OnAbout(wxCommandEvent &event) -> void
{
    wxMessageBox("ODBC Client", "ODBC Client", wxOK | wxICON_INFORMATION, this);
}
