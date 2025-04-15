cmake_minimum_required(VERSION 3.31)

include(cmake/LocalModulePath.cmake)
include(BuildType)
include(SetupConan)

# Set experimental flag to enable `import std` support from CMake.
# This must be enabled before C++ language support.
if ("${CMAKE_MAJOR_VERSION}" EQUAL "3")
	# This specific value changes as experimental support evolves. See
	# `Help/dev/experimental.rst` in the CMake source corresponding to
	# your CMake build for the exact value to use.
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
elseif ("${CMAKE_MAJOR_VERSION}" EQUAL "4")
	# This specific value changes as experimental support evolves. See
	# `Help/dev/experimental.rst` in the CMake source corresponding to
	# your CMake build for the exact value to use.
    message(STATUS "Setting experimental support for CXX_IMPORT_STD")
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
endif()


project(ODBC-Cmd VERSION 0.1 DESCRIPTION "Portable ODBC library and tools" LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_MODULE_STD 1)
set(CMAKE_INSTALL_MESSAGE LAZY)

include(SetupBoost)

include(odbc++.cmake)
include(dbcmd.cmake)
include(odbc-client.cmake)
