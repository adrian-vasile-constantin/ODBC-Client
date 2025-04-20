find_package(wxWidgets)

set(ODBC_CLIENT_SOURCES
	"src/odbc-client/wx/Base.DataStruct.cc"
	"src/odbc-client/wx/Base.cc"
	"src/odbc-client/wx/Core.DataStruct.cc"
	"src/odbc-client/wx/Core.Defs.cc"
	"src/odbc-client/wx/Core.DeviceContext.cc"
	"src/odbc-client/wx/Core.GDI.cc"
	"src/odbc-client/wx/Core.Miscellaneous.cc"
	"src/odbc-client/wx/Core.Event.cc"
	"src/odbc-client/wx/Core.Controls.cc"
	"src/odbc-client/wx/Core.Layout.cc"
	"src/odbc-client/wx/Core.TopLevel.cc"
	"src/odbc-client/wx/Core.Grid.cc"
	"src/odbc-client/wx/Core.PropertyGrid.cc"
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

set(WXWIDGETS_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/wxwidgets/3.2.6/$<CONFIG>/x86_64/lib/vc_x64_dll")
set(PCRE_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/pcre2/10.42/$<CONFIG>/x86_64/bin")
set(TIFF_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/libtiff/4.6.0/$<CONFIG>/x86_64/bin")
set(PNG_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/libpng/1.6.47/$<CONFIG>/x86_64/bin")
set(JPEG_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/libjpeg/9e/$<CONFIG>/x86_64/bin")
set(DEFLATE_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/libdeflate/1.22/$<CONFIG>/x86_64/bin")
set(JBIG_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/jbig/20160605/$<CONFIG>/x86_64/bin")
set(XZ_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/xz_utils/5.4.5/$<CONFIG>/x86_64/bin")
set(ZSTD_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/zstd/1.5.5/$<CONFIG>/x86_64/bin")
SET(WEBP_DLL_DIR "${CMAKE_BINARY_DIR}/deps/full_deploy/host/libwebp/1.3.2/$<CONFIG>/x86_64/bin")

add_custom_command(TARGET odbc-client POST_BUILD
    # COMMAND ${CMAKE_COMMAND} -E echo ${CMAKE_COMMAND} -E copy_if_different ${WXWIDGETS_DLL_DIR}/wxmsw32ud_propgrid_vc_x64_custom.dll ${WXWIDGETS_DLL_DIR}/wxbase32ud_vc_x64_custom.dll "$<TARGET_FILE_DIR:odbc-client>/"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${WXWIDGETS_DLL_DIR}/wxmsw32ud_propgrid_vc_x64_custom.dll" "$<TARGET_FILE_DIR:odbc-client>/wxmsw32ud_propgrid_vc_x64_custom.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${WXWIDGETS_DLL_DIR}/wxmsw32ud_core_vc_x64_custom.dll" "$<TARGET_FILE_DIR:odbc-client>/wxmsw32ud_core_vc_x64_custom.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${WXWIDGETS_DLL_DIR}/wxbase32ud_vc_x64_custom.dll" "$<TARGET_FILE_DIR:odbc-client>/wxbase32ud_vc_x64_custom.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PCRE_DLL_DIR}/pcre2-16d.dll" "$<TARGET_FILE_DIR:odbc-client>/pcre2-16d.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${TIFF_DLL_DIR}/tiffd.dll" "$<TARGET_FILE_DIR:odbc-client>/tiffd.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${JPEG_DLL_DIR}/libjpeg-9.dll" "$<TARGET_FILE_DIR:odbc-client>/libjpeg-9.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PNG_DLL_DIR}/libpng16d.dll" "$<TARGET_FILE_DIR:odbc-client>/libpng16d.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DEFLATE_DLL_DIR}/deflate.dll" "$<TARGET_FILE_DIR:odbc-client>/deflate.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${JBIG_DLL_DIR}/jbig.dll" "$<TARGET_FILE_DIR:odbc-client>/jbig.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${XZ_DLL_DIR}/liblzma.dll" "$<TARGET_FILE_DIR:odbc-client>/liblzma.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${ZSTD_DLL_DIR}/zstd.dll" "$<TARGET_FILE_DIR:odbc-client>/zstd.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${WEBP_DLL_DIR}/webp.dll" "$<TARGET_FILE_DIR:odbc-client>/webp.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${WEBP_DLL_DIR}/sharpyuv.dll" "$<TARGET_FILE_DIR:odbc-client>/sharpyuv.dll"
)
