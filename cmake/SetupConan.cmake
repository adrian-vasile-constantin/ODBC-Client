include_guard(GLOBAL)

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libs/cmake-conan/conan_provider.cmake")
    find_package(Git)

    if (Git_FOUND)
	execute_process(COMMAND "${GIT_EXECUTABLE}" "submodule" "update" "--init" "libs/camke-conan"
	    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	    COMMAND ECHO STDOUT COMMAND ERROR_IS_FATAL ANY)
    else()
	message(SEND_ERROR "Uninitialized git submodule libs/cmake-conan.")
    endif()
endif()

if (NOT CMAKE_PROJECT_TOP_LEVEL_INCLUDES)
    set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES "libs/cmake-conan/conan_provider.cmake")
endif()

list(APPEND CONAN_INSTALL_ARGS "--build=missing" "-s" "compiler.cppstd=20" "--deployer=full_deploy" "--deployer-folder=deps")

# set(CONAN_HOST_PROFILE "default;auto-cmake")
# set(CONAN_BUILD_PROFILE "../path/to/profile/...")
