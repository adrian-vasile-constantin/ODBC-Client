module;

#include "intellisense/odbc-client-headers.hh"

export module OdbcFrame;

#if !defined MSVC_INTELLISENSE
import local.wx.Core;

namespace wx = local::wx;
#endif

export class OdbcFrame: public wx::Frame
{
public:
    OdbcFrame();

private:
    auto OnConnect(wx::CommandEvent &event) -> void;
    auto OnExit(wx::CommandEvent &event) -> void;
    auto OnAbout(wx::CommandEvent &event) -> void;
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
    : wxFrame(nullptr, wx::ID_ANY, "ODBC Client")
{
    auto menuFile = unique_ptr<wx::Menu> { new wx::Menu() };

    menuFile->Append(ID_Connect, "Connect...", "Connect to selected ODBC driver or Data Source Name");
    menuFile->AppendSeparator();
    menuFile->Append(wx::ID_EXIT);

    auto menuHelp = unique_ptr<wx::Menu> { new wx::Menu() };
    menuHelp->Append(wx::ID_ABOUT);

    auto menuBar = unique_ptr<wx::MenuBar> { new wx::MenuBar() };
    menuBar->Append(menuFile.release(), "&ODBC");
    menuBar->Append(menuHelp.release(), "&Help");

    SetMenuBar(menuBar.release());

    CreateStatusBar();
    SetStatusText("Connect to ODBC data source");

    Bind(wx::EVT_MENU, &OdbcFrame::OnConnect, this, ID_Connect);
    Bind(wx::EVT_MENU, &OdbcFrame::OnExit, this, wx::ID_EXIT);
    Bind(wx::EVT_MENU, &OdbcFrame::OnAbout, this, wx::ID_ABOUT);
}

auto OdbcFrame::OnExit(wx::CommandEvent &event) -> void
{
    Close(true);
}

auto OdbcFrame::OnConnect(wx::CommandEvent &event) -> void
{
    wx::MessageBox("ODBC Connect", "ODBC Client", wx::OK | wx::ICON_INFORMATION, this);
}

auto OdbcFrame::OnAbout(wx::CommandEvent &event) -> void
{
    wx::MessageBox("ODBC Client", "ODBC Client", wx::OK | wx::ICON_INFORMATION, this);
}
