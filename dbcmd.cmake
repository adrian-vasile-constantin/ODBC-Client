include(GNUInstallDirs)
include(VersionInfo)

set(SQLODBC_SOURCES
    "src/dbcmd/external/boost/iostreams.cc"
    "src/dbcmd/Context.cc"
    "src/dbcmd/CommandHandler.cc"
    "src/dbcmd/lib/HistoryList.cc"
    "src/dbcmd/lib/HistoryFile.cc"
    "src/dbcmd/lib/HistoryCache.cc"
    "src/dbcmd/browseConnect.cc"
    "src/dbcmd/Drivers.cc"
    "src/dbcmd/ShellCommand.cc"
    "src/dbcmd/ChDirCommand.cc"
    "src/dbcmd/EnvCommand.cc"
    "src/dbcmd/EchoCommand.cc"
    "src/dbcmd/HelpCommand.cc"
    "src/dbcmd/DiagnosticRecord.cc"
    "src/sqlodbc.cc")

add_executable(dbcmd)
target_sources(dbcmd PRIVATE FILE_SET CXX_MODULES FILES ${SQLODBC_SOURCES})
target_link_libraries(dbcmd PRIVATE odbc++) # boost_iostreams
target_compile_features(dbcmd PRIVATE cxx_std_23)

if("23" IN_LIST CMAKE_CXX_COMPILER_IMPORT_STD)
    set_target_properties(dbcmd PROPERTIES CXX_MODULE_STD ON)
else()
    message(STATUS "CXX compiler import std: ${CMAKE_CXX_COMPILER_IMPORT_STD}")
    message(SEND_ERROR "C++ support for import std not implemented in the build system, see available compiler options")
endif()

set_target_properties(dbcmd
    PROPERTIES
	MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue"
	COMPILE_PDB_NAME "sqlodbc.compile"
	CXX_SCAN_FOR_MODULES ON
	INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

VersionInfo_Generate(TARGET dbcmd
#    FILE_FLAG_PATCHED FALSE
#    FILE_FLAG_PRERELEASE TRUE
#    PRIVATE_BUILD ""
#    SPECIAL_BUILD ""
    COMMENTS "ODBC Command Prompt and command interpretter"
    FILE_DESCRIPTION "ODBC Command Prompt"
    LEGAL_COPYRIGHT "Copyright (C) 2025 Timothy Madden"
    ICON "icon/db_plates.ico"
)

if(WIN32)
    find_library(SHELL32_LIBRARY_PATH "Shell32" REQUIRED)
    target_compile_definitions(dbcmd PRIVATE WINDOWS)
    target_link_libraries(dbcmd PRIVATE "${SHELL32_LIBRARY_PATH}")

    if(MSVC)
	target_include_directories(dbcmd PRIVATE "src/dbcmd")
    endif()
endif()

install(TARGETS dbcmd EXPORT dbcmd
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT Runtime)

install(EXPORT dbcmd DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake" COMPONENT Development)
