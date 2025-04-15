module;

#include "intellisense/odbc-client-headers.hh"
#include "../odbc++/intellisense/odbcxx_project_headers.hh"

#include <wx/artprov.h>

export module OdbcFrame;

#if !defined MSVC_INTELLISENSE
import wx.Core;
#endif

export class OdbcFrame: public wx::Frame
{
public:
    OdbcFrame();

private:
    auto PopulatePanel() -> void;

    auto OnConnect(wx::CommandEvent &event) -> void;
    auto OnExit(wx::CommandEvent &event) -> void;
    auto OnAbout(wx::CommandEvent &event) -> void;
};

module :private;

#if !defined MSVC_INTELLISENSE
import std;
import odbc.Environment;
#endif

using std::unique_ptr;

using wx::OK;
using wx::ID_OK;
using wx::ID_ABOUT;
using wx::ID_EXIT;
using wx::ID_CANCEL;
using wx::ID_ANY;
using wx::EVT_MENU;
using wx::ICON_INFORMATION;
using wx::EXPAND;
using wx::ALIGN_RIGHT;
using wx::HORIZONTAL;
using wx::VERTICAL;
using wx::ALIGN_CENTER_HORIZONTAL;
using wx::ALIGN_CENTER_VERTICAL;
using wx::TOP;
using wx::BOTTOM;
using wx::LEFT;
using wx::RIGHT;
using wx::Size;
using wx::DefaultPosition;
using wx::DefaultSize;
using wx::CommandEvent;
using wx::Menu;
using wx::MenuBar;
using wx::Panel;
using wx::Button;
using wx::BitmapButton;
using wx::StaticText;
using wx::ListBox;
using wx::ListCtrl;
using wx::ListItem;
using wx::ListView;
using wx::Display;
using wx::ArtProvider;
using wx::StdDialogButtonSizer;
using wx::BoxSizer;
using wx::GridBagSizer;
using wx::SizerFlags;
using wx::GBPosition;
using wx::DefaultSpan;
using wx::GBSpan;
using wx::MessageBox;
using wx::PersistentRegisterAndRestore;

using wx::LC_LIST;
using wx::LC_REPORT;
using wx::LC_SINGLE_SEL;
using wx::LC_EDIT_LABELS;
using wx::LC_ALIGN_LEFT;
using wx::LC_ALIGN_TOP;
using wx::LC_HRULES;
using wx::LC_VRULES;
using wx::LIST_FORMAT_LEFT;
using wx::LIST_AUTOSIZE;
using wx::LIST_AUTOSIZE_USEHEADER;

enum
{
    ID_Connect = 2,
    ID_AddDriver,
    ID_RemoveDriver,
    ID_BrowseConnect,
    ID_DriverList,
    ID_ConnectString,
    ID_UserDSNList,
    ID_SystemDSNList,
    ID_AddUserDSN,
    ID_RemoveUserDSN,
    ID_ManageUserDSNs,
    ID_ConfigureUserDSN,
    ID_DeleteUserDSN,
    ID_AddSystemDSN,
    ID_RemoveSystemDSN,
    ID_ManageSystemDSNs,
    ID_ConfigureSystemDSN,
    ID_DeleteSystemDSN
};

static const Size defaultSize { 800, 700 };

OdbcFrame::OdbcFrame()
    : wxFrame(nullptr, ID_ANY, "Connection - ODBC Client", DefaultPosition, defaultSize)
{
    // Resize to fit the display if necessary
    if (Display display; GetSize().GetHeight() > display.GetClientArea().GetHeight() || GetSize().GetWidth() > display.GetClientArea().GetWidth())
	SetSize(display.GetClientArea().GetSize());

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
    SetStatusText("Create connection string or select existing Data Source Name (DSN)");

    PopulatePanel();
    PersistentRegisterAndRestore(this, "Connection Window");

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

auto OdbcFrame::PopulatePanel() -> void
{
    auto panel = new Panel(this);
    auto connectionString = new ListCtrl(panel, ID_ConnectString, DefaultPosition, DefaultSize, LC_REPORT | LC_SINGLE_SEL | LC_EDIT_LABELS | LC_ALIGN_LEFT | LC_HRULES | LC_VRULES);
    connectionString->InsertColumn(0, "Name", LIST_FORMAT_LEFT, 150);
    connectionString->InsertColumn(1, "Value", LIST_FORMAT_LEFT, 150);
    connectionString->InsertItem(0, "");
    connectionString->SetItem(0, 1, "");

    auto driverList = new ListBox(panel, ID_DriverList);
    odbc::Environment env;

    for (auto const &[description, attributes] : env.drivers())
	driverList->Append(description);

    auto userDsnList = new ListView(panel, ID_UserDSNList);
    userDsnList->InsertColumn(0, "DSN", LIST_FORMAT_LEFT | LIST_AUTOSIZE, 150);
    userDsnList->InsertColumn(1, "Drver", LIST_FORMAT_LEFT | LIST_AUTOSIZE, 250);

    int i = 0;

    for (auto const &[dsnName, driverName] : env.userDSNs())
    {
	auto nameItem = ListItem { }, driverItem = ListItem { };

	nameItem.SetId(i);
	nameItem.SetColumn(0);
	nameItem.SetText(dsnName);

	driverItem.SetId(i);
	driverItem.SetColumn(1);
	driverItem.SetText(driverName);

	userDsnList->InsertItem(nameItem);
	userDsnList->SetItem(driverItem);
    }

    auto systemDsnList = new ListView(panel, ID_SystemDSNList);
    systemDsnList->InsertColumn(0, "DSN", LIST_FORMAT_LEFT | LIST_AUTOSIZE, 150);
    systemDsnList->InsertColumn(1, "Driver", LIST_FORMAT_LEFT | LIST_AUTOSIZE, 250);

    i = 0;

    for (auto const &[dsnName, driverName] : env.systemDSNs())
    {
	auto nameItem = ListItem { }, driverItem = ListItem { };

	nameItem.SetId(i);
	nameItem.SetColumn(0);
	nameItem.SetText(dsnName);

	driverItem.SetId(i);
	driverItem.SetColumn(1);
	driverItem.SetText(driverName);

	systemDsnList->InsertItem(nameItem);
	systemDsnList->SetItem(driverItem);
    }

    auto gridBag = new GridBagSizer(10, 10);

    gridBag->Add(new StaticText(panel, ID_ANY, "Installed ODBC Drivers"), GBPosition { }, DefaultSpan, TOP | LEFT, 10);
    gridBag->Add(new StaticText(panel, ID_ANY, "Connection string fields:"), GBPosition { 0, 2 }, DefaultSpan, TOP, 10);
    gridBag->Add(new StaticText(panel, ID_ANY, "User Data Source Names (DSNs)"), GBPosition { 0, 4 }, DefaultSpan, TOP, 10);
    gridBag->Add(new StaticText(panel, ID_ANY, "System Data Source Names (DSNs)"), GBPosition { 3, 4 }, DefaultSpan, TOP | RIGHT, 10);

    gridBag->Add(driverList,	GBPosition { 1, 0 }, GBSpan { 4, 1 }, EXPAND | LEFT, 10);
    gridBag->Add(connectionString, GBPosition { 1, 2 }, GBSpan { 4, 1 },EXPAND);
    gridBag->Add(userDsnList,	GBPosition { 1, 4 }, DefaultSpan, EXPAND | RIGHT, 10);
    gridBag->Add(systemDsnList, GBPosition { 4, 4 }, DefaultSpan, EXPAND | RIGHT, 10);

    gridBag->Add(new Button(panel, ID_BrowseConnect, "BrowseConnect..."), GBPosition { 5, 0 }, DefaultSpan, ALIGN_RIGHT);

    auto dialogButtonSizer = new StdDialogButtonSizer();

    dialogButtonSizer->Add(new Button(panel, ID_OK,	"Connect"));
    dialogButtonSizer->AddSpacer(10);
    dialogButtonSizer->Add(new Button(panel, ID_CANCEL, "Cancel"));

    gridBag->Add(dialogButtonSizer, GBPosition { 5, 2 }, DefaultSpan, ALIGN_RIGHT | BOTTOM, 10);

    auto userDsnButtonSizer = new BoxSizer(HORIZONTAL);

    userDsnButtonSizer->Add(new Button(panel, ID_ManageUserDSNs,   "Manage DSNs..."));
    userDsnButtonSizer->AddSpacer(10);
    userDsnButtonSizer->Add(new Button(panel, ID_ConfigureUserDSN, "Configure DSN..."));
    userDsnButtonSizer->AddSpacer(10);
    userDsnButtonSizer->Add(new Button(panel, ID_DeleteUserDSN,	   "Remove DSN..."));

    gridBag->Add(userDsnButtonSizer, GBPosition { 2, 4 }, DefaultSpan, ALIGN_RIGHT | RIGHT, 10);

    auto systemDsnButtonSizer = new BoxSizer(HORIZONTAL);

    systemDsnButtonSizer->Add(new Button(panel, ID_ManageSystemDSNs, "Manage DSNs"));
    systemDsnButtonSizer->AddSpacer(10);
    systemDsnButtonSizer->Add(new Button(panel, ID_ConfigureSystemDSN, "Configure DSN..."));
    systemDsnButtonSizer->AddSpacer(10);
    systemDsnButtonSizer->Add(new Button(panel, ID_DeleteSystemDSN, "Remove DSN..."));

    gridBag->Add(systemDsnButtonSizer, GBPosition { 5, 4 }, DefaultSpan, ALIGN_RIGHT | RIGHT | BOTTOM, 10);

    auto driverTransferSizer = new BoxSizer(VERTICAL);
    driverTransferSizer->Add(new BitmapButton(panel, ID_AddDriver, ArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_BUTTON)));
    driverTransferSizer->AddSpacer(10);
    driverTransferSizer->Add(new BitmapButton(panel, ID_RemoveDriver, ArtProvider::GetBitmap(wxART_GO_BACK, wxART_BUTTON)));

    gridBag->Add(driverTransferSizer, GBPosition { 1, 1 }, DefaultSpan, ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL);

    auto userDsnTransferSizer = new BoxSizer(VERTICAL);
    userDsnTransferSizer->Add(new BitmapButton(panel, ID_AddUserDSN, ArtProvider::GetBitmap(wxART_GO_BACK, wxART_BUTTON)));
    userDsnTransferSizer->AddSpacer(10);
    userDsnTransferSizer->Add(new BitmapButton(panel, ID_RemoveUserDSN, ArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_BUTTON)));

    gridBag->Add(userDsnTransferSizer, GBPosition { 1, 3 }, DefaultSpan, ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL);

    auto systemDsnTransferSizer = new BoxSizer(VERTICAL);
    systemDsnTransferSizer->Add(new BitmapButton(panel, ID_AddSystemDSN, ArtProvider::GetBitmap(wxART_GO_BACK, wxART_BUTTON)));
    systemDsnTransferSizer->AddSpacer(10);
    systemDsnTransferSizer->Add(new BitmapButton(panel, ID_RemoveSystemDSN, ArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_BUTTON)));

    gridBag->Add(systemDsnTransferSizer, GBPosition { 4, 3 }, DefaultSpan, ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL);

    gridBag->AddGrowableCol(0, 1);
    gridBag->AddGrowableCol(2, 1);
    gridBag->AddGrowableCol(4, 1);

    gridBag->AddGrowableRow(1, 1);
    gridBag->AddGrowableRow(4, 1);

    panel->SetSizerAndFit(gridBag);
}
