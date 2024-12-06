include(GNUInstallDirs)
include(GenerateExportHeader)
include(VersionInfo)

set(ODBCXX_MODULES
    "src/odbc++/external/boost/iostreams.cc"
    "src/odbc++/WindowsCategory.cc"
    "src/odbc++/Handle.cc"
    "src/odbc++/Environment.cc"
    "src/odbc++/Connection.cc"
    "src/odbc++/SQLDiagnosticException.cc"
    "src/odbc++/FileDescriptorDevice.cc"
    "src/odbc++/FileDescriptorSink.cc"
    "src/odbc++/FileDescriptorSource.cc")

add_library(odbc++ SHARED)
target_sources(odbc++ PUBLIC FILE_SET CXX_MODULES TYPE CXX_MODULES BASE_DIRS "src/odbc++" FILES ${ODBCXX_MODULES})
target_include_directories(odbc++ PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
set_target_properties(odbc++
    PROPERTIES
	MSVC_DEBUG_INFORMATION_FORMAT "EditAndContinue"
	COMPILE_PDB_NAME "odbc++.compile"
	CXX_SCAN_FOR_MODULES ON
	INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

target_compile_features(odbc++ PUBLIC cxx_std_23)
target_link_libraries(odbc++ PUBLIC local_boost::iostreams)

generate_export_header(odbc++
	BASE_NAME odbcxx
	EXPORT_FILE_NAME "ODBCXX_Export.h"
	INCLUDE_GUARD_NAME SQL_ODBCXX_EXPORT_H
	EXPORT_MACRO_NAME ODBCXX_EXPORT
	NO_EXPORT_MACRO_NAME MODULE_LOCAL)

target_include_directories(odbc++ PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")

if("23" IN_LIST CMAKE_CXX_COMPILER_IMPORT_STD)
    set_target_properties(odbc++ PROPERTIES CXX_MODULE_STD ON)
else()
    message(STATUS "CXX compiler import std: ${CMAKE_CXX_COMPILER_IMPORT_STD}")
    message(SEND_ERROR "C++ support for import std not implemented in the build system, see available compiler options")
endif()

if(WIN32)
    find_library(ODBC_LIBRARY_PATH "ODBC32" REQUIRED)
    target_link_libraries(odbc++ PUBLIC "$<BUILD_INTERFACE:${ODBC_LIBRARY_PATH}>" "$<INSTALL_INTERFACE:ODBC32>")
    target_compile_definitions(odbc++ PUBLIC WINDOWS)
endif()

VersionInfo_Generate(TARGET odbc++
    COMMENTS "C++ Library for ODBC"
    FILE_DESCRIPTION "C++ Library for ODBC"
    LEGAL_COPYRIGHT "Copyright © 2025 Timothy Madden"
    ICON "icon/db_plates.ico"
)

install(TARGETS odbc++ EXPORT odbc++
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/odbc++" COMPONENT Development
    FILE_SET HEADERS DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}" COMPONENT Development
    FILE_SET CXX_MODULES DESTINATION "${CMAKE_INSTALL_DATADIR}/cxx/modules/src/odbc++-${PROJECT_VERSION}" COMPONENT Development
    CXX_MODULES_BMI DESTINATION "${CMAKE_INSTALL_DATADIR}/cxx/modules/bmi/${CMAKE_CXX_COMPILER_ID}/${CMAKE_CXX_COMPILER_VERSION}/odbc++-${PROJECT_VERSION}/" COMPONENT Development
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT Development
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT Runtime NAMELINK_COMPONENT Development
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT Runtime)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ODBCXX_Export.h"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/odbc++" COMPONENT Development)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ODBCXX_Export.h"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/cxx/modules/src/odbc++-${PROJECT_VERSION}" COMPONENT Development)

install(DIRECTORY "src/odbc++/intellisense" DESTINATION "${CMAKE_INSTALL_DATADIR}/cxx/modules/src/odbc++-${PROJECT_VERSION}" COMPONENT Development)

install(EXPORT odbc++ COMPONENT Development DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake")
