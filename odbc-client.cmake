find_package(wxWidgets)

set(ODBC_CLIENT_SOURCES
	"src/odbc-client/wx/Base.DataStruct.cc"
	"src/odbc-client/wx/Base.cc"
	"src/odbc-client/wx/Core.DataStruct.cc"
	"src/odbc-client/wx/Core.Defs.cc"
	"src/odbc-client/wx/Core.GDI.cc"
	"src/odbc-client/wx/Core.Event.cc"
	"src/odbc-client/wx/Core.Controls.cc"
	"src/odbc-client/wx/Core.Layout.cc"
	"src/odbc-client/wx/Core.TopLevel.cc"
	"src/odbc-client/wx/Core.cc"
	"src/odbc-client/OdbcFrame.cc"
	"src/odbc-client/OdbcApp.cc")

add_executable(odbc-client)
target_sources(odbc-client PRIVATE FILE_SET CXX_MODULES FILES ${ODBC_CLIENT_SOURCES})
target_include_directories(odbc-client PRIVATE "src/odbc-client")
target_link_libraries(odbc-client PRIVATE odbc++ wxWidgets::wxWidgets)
target_compile_features(odbc-client PRIVATE cxx_std_23)
set_target_properties(odbc-client PROPERTIES WIN32_EXECUTABLE ON)

if("23" IN_LIST CMAKE_CXX_COMPILER_IMPORT_STD)
    set_target_properties(odbc-client PROPERTIES CXX_MODULE_STD ON)
else()
    message(STATUS "CXX compiler import std: ${CMAKE_CXX_COMPILER_IMPORT_STD}")
    message(SEND_ERROR "C++ support for import std not implemented in the build system, see available compiler options")
endif()

set_target_properties(odbc-client
    PROPERTIES
	MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue"
	COMPILE_PDB_NAME "odbc-client.compile"
	CXX_SCAN_FOR_MODULES ON
	INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)

string(ASCII 169 COPYRIGHT_SYMBOL)  # literal '©'

VersionInfo_Generate(TARGET odbc-client
#    FILE_FLAG_PATCHED FALSE
#    FILE_FLAG_PRERELEASE TRUE
#    PRIVATE_BUILD ""
#    SPECIAL_BUILD ""
    COMMENTS "ODBC GUI Client"
    FILE_DESCRIPTION "ODBC Client"
    LEGAL_COPYRIGHT "Copyright ${COPYRIGHT_SYMBOL} 2025 Adrian Vasile Constantin"
    #    ICON "icon/db_plates.ico"
)
