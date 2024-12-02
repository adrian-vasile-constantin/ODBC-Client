
if(NOT DEFINED GIT_EXECUTABLE OR NOT DEFINED GIT_WORKING_TREE OR NOT TEMPLATE_FILE OR NOT RESOURCE_FILE OR NOT TARGET_SOURCE_DIRECTORY)
    message(SEND_ERROR "Missing command line definitions for cmake script.")
endif()

if(PATCHED IN_LIST CHECK_CONFIG)
    execute_process(COMMAND ${GIT_EXECUTABLE} -C "${TARGET_SOURCE_DIRECTORY}" diff --exit-code --quiet --no-ext-diff --
	COMMAND_ECHO STDOUT
	RESULT_VARIABLE DIFF_EXIT_CODE)
endif()
