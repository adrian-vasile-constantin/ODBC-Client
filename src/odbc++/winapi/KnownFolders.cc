module;

#if defined(_WINDOWS)
# if defined(_M_AMD64) && !defined(_AMD64_)
#   define _AMD64_
# endif
# if defined(_M_IX86) && !defined(_X68_)
#  define _X86_
# endif
#endif

#define INITKNOWNFOLDERS

#include <windef.h>
#include <KnownFolders.h>

export module winapi.KnownFolders;

namespace winapi
{
    export using ::FOLDERID_AccountPictures;
    export using ::FOLDERID_AddNewPrograms;
    export using ::FOLDERID_AdminTools;

    // ThESE FOLDERIDS are used internally by.NET applications to enable cross - platform app functionality.They are not intended to be used directly from an application.

    export using ::FOLDERID_AppDataDesktop;
    export using ::FOLDERID_AppDataDocuments;
    export using ::FOLDERID_AppDataFavorites;
    export using ::FOLDERID_AppDataProgramData;


    export using ::FOLDERID_ApplicationShortcuts;
    export using ::FOLDERID_AppsFolder;
    export using ::FOLDERID_AppUpdates;
    export using ::FOLDERID_CameraRoll;
    export using ::FOLDERID_CDBurning;
    export using ::FOLDERID_ChangeRemovePrograms;
    export using ::FOLDERID_CommonAdminTools;
    export using ::FOLDERID_CommonOEMLinks;
    export using ::FOLDERID_CommonPrograms;
    export using ::FOLDERID_CommonStartMenu;
    export using ::FOLDERID_CommonStartup;
    export using ::FOLDERID_CommonTemplates;
    export using ::FOLDERID_ComputerFolder;
    export using ::FOLDERID_ConflictFolder;
    export using ::FOLDERID_ConnectionsFolder;
    export using ::FOLDERID_Contacts;
    export using ::FOLDERID_ControlPanelFolder;
    export using ::FOLDERID_Cookies;
    export using ::FOLDERID_Desktop;
    export using ::FOLDERID_DeviceMetadataStore;
    export using ::FOLDERID_Documents;
    export using ::FOLDERID_DocumentsLibrary;
    export using ::FOLDERID_Downloads;
    export using ::FOLDERID_Favorites;
    export using ::FOLDERID_Fonts;
    export using ::FOLDERID_Games;		// deprecated in Windows 10, version 1803 and later versions.In these versions, it returns 0x80070057 - E_INVALIDARG
    export using ::FOLDERID_GameTasks;
    export using ::FOLDERID_History;
    export using ::FOLDERID_HomeGroup;
    export using ::FOLDERID_HomeGroupCurrentUser;
    export using ::FOLDERID_ImplicitAppShortcuts;
    export using ::FOLDERID_InternetCache;
    export using ::FOLDERID_InternetFolder;
    export using ::FOLDERID_Libraries;
    export using ::FOLDERID_Links;
    export using ::FOLDERID_LocalAppData;
    export using ::FOLDERID_LocalAppDataLow;
    export using ::FOLDERID_LocalizedResourcesDir;
    export using ::FOLDERID_Music;
    export using ::FOLDERID_MusicLibrary;
    export using ::FOLDERID_NetHood;
    export using ::FOLDERID_NetworkFolder;
    export using ::FOLDERID_Objects3D;
    export using ::FOLDERID_OriginalImages;
    export using ::FOLDERID_PhotoAlbums;
    export using ::FOLDERID_PicturesLibrary;
    export using ::FOLDERID_Pictures;
    export using ::FOLDERID_Playlists;
    export using ::FOLDERID_PrintersFolder;
    export using ::FOLDERID_PrintHood;
    export using ::FOLDERID_Profile;
    export using ::FOLDERID_ProgramData;
    export using ::FOLDERID_ProgramFiles;
    export using ::FOLDERID_ProgramFilesX64;
    export using ::FOLDERID_ProgramFilesX86;
    export using ::FOLDERID_ProgramFilesCommon;
    export using ::FOLDERID_ProgramFilesCommonX64;
    export using ::FOLDERID_ProgramFilesCommonX86;
    export using ::FOLDERID_Programs;
    export using ::FOLDERID_Public;
    export using ::FOLDERID_PublicDesktop;
    export using ::FOLDERID_PublicDocuments;
    export using ::FOLDERID_PublicDownloads;
    export using ::FOLDERID_PublicGameTasks;
    export using ::FOLDERID_PublicLibraries;
    export using ::FOLDERID_PublicMusic;
    export using ::FOLDERID_PublicPictures;
    export using ::FOLDERID_PublicRingtones;
    export using ::FOLDERID_PublicUserTiles;
    export using ::FOLDERID_PublicVideos;
    export using ::FOLDERID_QuickLaunch;
    export using ::FOLDERID_Recent;
    // export using ::FOLDERID_RecordedTV;	    // Undefined as of Windows 7.
    export using ::FOLDERID_RecordedTVLibrary;
    export using ::FOLDERID_RecycleBinFolder;
    export using ::FOLDERID_ResourceDir;
    export using ::FOLDERID_Ringtones;
    export using ::FOLDERID_RoamingAppData;
    export using ::FOLDERID_RoamedTileImages;
    export using ::FOLDERID_RoamingTiles;
    export using ::FOLDERID_SampleMusic;
    export using ::FOLDERID_SamplePictures;
    export using ::FOLDERID_SamplePlaylists;
    export using ::FOLDERID_SampleVideos;
    export using ::FOLDERID_SavedGames;
    export using ::FOLDERID_SavedPictures;
    export using ::FOLDERID_SavedPicturesLibrary;
    export using ::FOLDERID_SavedSearches;
    export using ::FOLDERID_Screenshots;
    export using ::FOLDERID_SEARCH_CSC;
    export using ::FOLDERID_SearchHistory;
    export using ::FOLDERID_SearchHome;
    export using ::FOLDERID_SEARCH_MAPI;
    export using ::FOLDERID_SearchTemplates;
    export using ::FOLDERID_SendTo;
    export using ::FOLDERID_SidebarDefaultParts;
    export using ::FOLDERID_SidebarParts;
    export using ::FOLDERID_SkyDrive;
    export using ::FOLDERID_SkyDriveCameraRoll;
    export using ::FOLDERID_SkyDriveDocuments;
    export using ::FOLDERID_SkyDrivePictures;
    export using ::FOLDERID_StartMenu;
    export using ::FOLDERID_Startup;
    export using ::FOLDERID_SyncManagerFolder;
    export using ::FOLDERID_SyncResultsFolder;
    export using ::FOLDERID_SyncSetupFolder;
    export using ::FOLDERID_System;
    export using ::FOLDERID_SystemX86;
    export using ::FOLDERID_Templates;
    // export using ::FOLDERID_TreeProperties;	// Unsupported as of Windows 7.
    export using ::FOLDERID_UserPinned;
    export using ::FOLDERID_UserProfiles;
    export using ::FOLDERID_UserProgramFiles;
    export using ::FOLDERID_UserProgramFilesCommon;
    export using ::FOLDERID_UsersFiles;
    export using ::FOLDERID_UsersLibraries;
    export using ::FOLDERID_Videos;
    export using ::FOLDERID_VideosLibrary;
    export using ::FOLDERID_Windows;

    export using ::FOLDERID_SystemX86;
    export using ::FOLDERID_ProgramFilesX86;
    export using ::FOLDERID_ProgramFilesX64;

    export using ::FOLDERID_ProgramFilesCommonX86;
    export using ::FOLDERID_ProgramFilesCommonX64;
}
