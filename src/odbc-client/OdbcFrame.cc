module;

#include "intellisense/odbc-client-headers.hh"
#include "../odbc++/intellisense/odbcxx_project_headers.hh"

#include <wx/artprov.h>
#include <wx/listctrl.h>

export module OdbcFrame;

#if !defined MSVC_INTELLISENSE
import std;
import wx.Base;
import wx.Core;
#endif

export class OdbcFrame: public wx::Frame
{
public:
    OdbcFrame();

private:
    std::unique_ptr<wx::Panel> panel;
    std::unique_ptr<wx::ListCtrl> driverList;
    std::unique_ptr<wx::ListCtrl> connectionString;
    std::unique_ptr<wx::ListView> userDsnList;
    std::unique_ptr<wx::ListView> systemDsnList;

    auto PopulatePanel() -> void;

    auto OnConnect(wx::CommandEvent &event) -> void;
    auto OnExit(wx::CommandEvent &event) -> void;
    auto OnAbout(wx::CommandEvent &event) -> void;
    auto OnResize(wx::SizeEvent &event) -> void;
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
using wx::EVT_SIZE;
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
using wx::String;
using wx::Coord;
using wx::PaintDC;
using wx::ClientDC;
using wx::Size;
using wx::DefaultPosition;
using wx::DefaultSize;
using wx::CommandEvent;
using wx::SizeEvent;
using wx::Menu;
using wx::MenuBar;
using wx::Frame;
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
using wx::LC_VIRTUAL;
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

static const Size defaultSize { 800, 550 };

OdbcFrame::OdbcFrame()
    : Frame(nullptr, ID_ANY, "Connection - ODBC Client", DefaultPosition, defaultSize)
{
    // Resize to fit the display if necessary
    if (Display display; GetSize().GetHeight() > display.GetClientArea().GetHeight() || GetSize().GetWidth() > display.GetClientArea().GetWidth())
	SetSize(display.GetClientArea().GetSize());

    auto menuFile = unique_ptr<Menu> { new Menu() };

    menuFile->Append(ID_Connect, "Connect...", "Connect to selected ODBC driver, Data Source Name or connection string");
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
    // PersistentRegisterAndRestore(this, "Connection Window");

    Bind(EVT_MENU, &OdbcFrame::OnConnect, this, ID_Connect);
    Bind(EVT_MENU, &OdbcFrame::OnExit, this, ID_EXIT);
    Bind(EVT_MENU, &OdbcFrame::OnAbout, this, ID_ABOUT);
    // Bind(EVT_SIZE, &OdbcFrame::OnResize, this);
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

using std::vector;
using std::unique_ptr;
using namespace std::literals::string_literals;

auto OdbcFrame::OnResize(SizeEvent &sizeEvent) -> void
{
    panel->SetSize(GetClientSize());

    for (auto *dsnList: { &userDsnList, &systemDsnList })
    {
	auto  clientDC { ClientDC { dsnList->get() } };

	auto colCount { dsnList->get()->GetColumnCount() };
	auto colWidth { vector<int> { colCount, 0 } };
	auto rowCount { dsnList->get()->GetItemCount() };

	for (auto col = 0u; col < colCount; col++)
	    for (int row = 0u; row < rowCount; row++)
	    {
		auto text { dsnList->get()->GetItemText(row, col) };
		auto font { dsnList->get()->GetItemFont(row) };

		Coord w, h;

		clientDC.GetTextExtent(text, &w, &h, nullptr, nullptr, font.IsOk() ? &font : nullptr);

		if (w > colWidth[col])
		    colWidth[col] = w;
	    }

	for (int i = 0u; i < colWidth.size(); i++)
	{
	    if (dsnList->get()->GetColumnWidth(i) != colWidth[i] * 11 / 10)
		dsnList->get()->SetColumnWidth(i, dsnList->get()->FromPhys(colWidth[i] * 11 / 10));
	}
    }
}

auto OdbcFrame::PopulatePanel() -> void
{
    panel.reset(new Panel(this));
    connectionString.reset(new ListCtrl(panel.get(), ID_ConnectString, DefaultPosition, DefaultSize, LC_REPORT | LC_SINGLE_SEL | LC_EDIT_LABELS | LC_ALIGN_LEFT | LC_HRULES | LC_VRULES));
    connectionString->InsertColumn(0, "Name", LIST_FORMAT_LEFT);
    connectionString->InsertColumn(1, "Value", LIST_FORMAT_LEFT);
    connectionString->InsertItem(0, "");
    connectionString->SetItem(0, 1, "");
    connectionString->SetWindowStyle(connectionString->GetWindowStyle() | LC_VIRTUAL);
    connectionString->EnableAlternateRowColours();

    driverList.reset(new ListCtrl(panel.get(), ID_DriverList, DefaultPosition, DefaultSize, LC_REPORT | LC_SINGLE_SEL | LC_ALIGN_LEFT | LC_VRULES));
    driverList->InsertColumn(0, "Driver", LIST_FORMAT_LEFT);
    odbc::Environment env;

    int i = 0;

    for (auto const &[description, attributes] : env.drivers())
	driverList->InsertItem(i++, description);

    driverList->SetColumnWidth(0, LIST_AUTOSIZE);
    driverList->SetWindowStyle(driverList->GetWindowStyle() | LC_VIRTUAL);
    driverList->EnableAlternateRowColours();

    userDsnList.reset(new ListView(panel.get(), ID_UserDSNList));
    userDsnList->InsertColumn(0, "DSN", LIST_FORMAT_LEFT);
    userDsnList->InsertColumn(1, "Driver", LIST_FORMAT_LEFT);

    i = 0;

    for (auto const &[dsnName, driverName]: env.userDSNs())
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

    userDsnList->SetColumnWidth(0, LIST_AUTOSIZE);
    userDsnList->SetColumnWidth(1, LIST_AUTOSIZE);
    userDsnList->SetWindowStyle(userDsnList->GetWindowStyle() | LC_VIRTUAL);
    userDsnList->EnableAlternateRowColours();


    systemDsnList.reset(new ListView(panel.get(), ID_SystemDSNList));
    systemDsnList->InsertColumn(0, "DSN", LIST_FORMAT_LEFT);
    systemDsnList->InsertColumn(1, "Driver", LIST_FORMAT_LEFT);

    i = 0;

    for (auto const &[dsnName, driverName]: env.systemDSNs())
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

    systemDsnList->SetColumnWidth(0, LIST_AUTOSIZE);
    systemDsnList->SetColumnWidth(1, LIST_AUTOSIZE);
    systemDsnList->SetWindowStyle(systemDsnList->GetWindowStyle() | LC_VIRTUAL);
    systemDsnList->EnableAlternateRowColours();

    auto defaultBorder = 2 * SizerFlags::GetDefaultBorder();

    auto gridBag = new GridBagSizer(defaultBorder, defaultBorder);

    gridBag->Add(new StaticText(panel.get(), ID_ANY, "Installed ODBC Drivers"), GBPosition { }, DefaultSpan, TOP | LEFT, defaultBorder);
    gridBag->Add(new StaticText(panel.get(), ID_ANY, "Connection string fields:"), GBPosition { 0, 2 }, DefaultSpan, TOP, defaultBorder);
    gridBag->Add(new StaticText(panel.get(), ID_ANY, "User Data Source Names (DSNs)"), GBPosition { 0, 4 }, DefaultSpan, TOP, defaultBorder);
    gridBag->Add(new StaticText(panel.get(), ID_ANY, "System Data Source Names (DSNs)"), GBPosition { 3, 4 }, DefaultSpan, TOP | RIGHT, defaultBorder);

    gridBag->Add(driverList.get(), GBPosition { 1, 0 }, GBSpan { 4, 1 }, EXPAND | LEFT, defaultBorder);
    gridBag->Add(connectionString.get(), GBPosition { 1, 2 }, GBSpan { 4, 1 }, EXPAND);
    gridBag->Add(userDsnList.get(), GBPosition { 1, 4 }, DefaultSpan, EXPAND | RIGHT, defaultBorder);
    gridBag->Add(systemDsnList.get(), GBPosition { 4, 4 }, DefaultSpan, EXPAND | RIGHT, defaultBorder);

    gridBag->Add(new Button(panel.get(), ID_BrowseConnect, "BrowseConnect..."), GBPosition { 5, 0 }, DefaultSpan, ALIGN_RIGHT);

    auto dialogButtonSizer = new StdDialogButtonSizer();

    dialogButtonSizer->Add(new Button(panel.get(), ID_OK, "Connect"));
    dialogButtonSizer->AddSpacer(10);
    dialogButtonSizer->Add(new Button(panel.get(), ID_CANCEL, "Cancel"));

    gridBag->Add(dialogButtonSizer, GBPosition { 5, 2 }, DefaultSpan, ALIGN_RIGHT | BOTTOM, defaultBorder);

    auto userDsnButtonSizer = new BoxSizer(HORIZONTAL);

    userDsnButtonSizer->Add(new Button(panel.get(), ID_ManageUserDSNs, "Manage DSNs..."));
    userDsnButtonSizer->AddSpacer(10);
    userDsnButtonSizer->Add(new Button(panel.get(), ID_ConfigureUserDSN, "Configure DSN..."));
    userDsnButtonSizer->AddSpacer(10);
    userDsnButtonSizer->Add(new Button(panel.get(), ID_DeleteUserDSN, "Remove DSN..."));

    gridBag->Add(userDsnButtonSizer, GBPosition { 2, 4 }, DefaultSpan, ALIGN_RIGHT | RIGHT, defaultBorder);

    auto systemDsnButtonSizer = new BoxSizer(HORIZONTAL);

    systemDsnButtonSizer->Add(new Button(panel.get(), ID_ManageSystemDSNs, "Manage DSNs..."));
    systemDsnButtonSizer->AddSpacer(10);
    systemDsnButtonSizer->Add(new Button(panel.get(), ID_ConfigureSystemDSN, "Configure DSN..."));
    systemDsnButtonSizer->AddSpacer(10);
    systemDsnButtonSizer->Add(new Button(panel.get(), ID_DeleteSystemDSN, "Remove DSN..."));

    gridBag->Add(systemDsnButtonSizer, GBPosition { 5, 4 }, DefaultSpan, ALIGN_RIGHT | RIGHT | BOTTOM, defaultBorder);

    auto goForwardBitmap { ArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_BUTTON) };
    auto goBackBitmap { ArtProvider::GetBitmap(wxART_GO_BACK, wxART_BUTTON) };

    auto driverTransferSizer = new BoxSizer(VERTICAL);
    driverTransferSizer->Add(new BitmapButton(panel.get(), ID_AddDriver, goForwardBitmap, DefaultPosition, Size { goForwardBitmap.GetWidth() * 3, goForwardBitmap.GetHeight() }));
    driverTransferSizer->AddSpacer(10);
    driverTransferSizer->Add(new BitmapButton(panel.get(), ID_RemoveDriver, goBackBitmap, DefaultPosition, Size { goBackBitmap.GetWidth() * 3, goBackBitmap.GetHeight() }));

    gridBag->Add(driverTransferSizer, GBPosition { 1, 1 }, DefaultSpan, ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL);

    auto userDsnTransferSizer = new BoxSizer(VERTICAL);
    userDsnTransferSizer->Add(new BitmapButton(panel.get(), ID_AddUserDSN, goBackBitmap, DefaultPosition, Size { goBackBitmap.GetWidth() * 3, goBackBitmap.GetHeight() }));
    userDsnTransferSizer->AddSpacer(10);
    userDsnTransferSizer->Add(new BitmapButton(panel.get(), ID_RemoveUserDSN, goForwardBitmap, DefaultPosition, Size { goForwardBitmap.GetWidth() * 3, goForwardBitmap.GetHeight() }));

    gridBag->Add(userDsnTransferSizer, GBPosition { 1, 3 }, DefaultSpan, ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL);

    auto systemDsnTransferSizer = new BoxSizer(VERTICAL);
    systemDsnTransferSizer->Add(new BitmapButton(panel.get(), ID_AddSystemDSN, goBackBitmap, DefaultPosition, Size { goBackBitmap.GetWidth() * 3, goBackBitmap.GetHeight() }));
    systemDsnTransferSizer->AddSpacer(10);
    systemDsnTransferSizer->Add(new BitmapButton(panel.get(), ID_RemoveSystemDSN, goForwardBitmap, DefaultPosition, Size { goForwardBitmap.GetWidth() * 3, goForwardBitmap.GetHeight() }));

    gridBag->Add(systemDsnTransferSizer, GBPosition { 4, 3 }, DefaultSpan, ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL);

    gridBag->AddGrowableCol(0, 1);
    gridBag->AddGrowableCol(2, 1);
    gridBag->AddGrowableCol(4, 1);

    gridBag->AddGrowableRow(1, 1);
    gridBag->AddGrowableRow(4, 1);

    panel->SetSizerAndFit(gridBag);
}
