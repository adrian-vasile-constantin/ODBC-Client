module;

#include "intellisense/odbc-client-headers.hh"

export module OdbcFrame;

#if !defined MSVC_INTELLISENSE
import local.wx.Base;
import local.wx.Core;
#endif

namespace wx = local::wx;

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

using wx::OK;
using wx::ID_ABOUT;
using wx::ID_EXIT;
using wx::ID_ANY;
using wx::EVT_MENU;
using wx::ICON_INFORMATION;
using wx::CommandEvent;
using wx::Menu;
using wx::MenuBar;
using wx::MessageBox;

enum
{
    ID_Connect = 1
};

OdbcFrame::OdbcFrame()
    : wxFrame(nullptr, ID_ANY, "ODBC Client")
{
    auto menuFile = unique_ptr<Menu> { new Menu() };

    menuFile->Append(ID_Connect, "Connect...", "Connect to selected ODBC driver or Data Source Name");
    menuFile->AppendSeparator();
    menuFile->Append(ID_EXIT);

    auto menuHelp = unique_ptr<Menu> { new Menu() };
    menuHelp->Append(ID_ABOUT);

    auto menuBar = unique_ptr<MenuBar> { new MenuBar() };
    menuBar->Append(menuFile.release(), "&ODBC");
    menuBar->Append(menuHelp.release(), "&Help");

    SetMenuBar(menuBar.release());

    CreateStatusBar();
    SetStatusText("Connect to ODBC data source");

    Bind(EVT_MENU, &OdbcFrame::OnConnect, this, ID_Connect);
    Bind(EVT_MENU, &OdbcFrame::OnExit, this, ID_EXIT);
    Bind(EVT_MENU, &OdbcFrame::OnAbout, this, ID_ABOUT);
}

auto OdbcFrame::OnExit(CommandEvent &event) -> void
{
    Close(true);
}

auto OdbcFrame::OnConnect(CommandEvent &event) -> void
{
    MessageBox("ODBC Connect", "ODBC Client", OK | ICON_INFORMATION, this);
}

auto OdbcFrame::OnAbout(CommandEvent &event) -> void
{
    MessageBox("ODBC Client", "ODBC Client", OK | ICON_INFORMATION, this);
}
