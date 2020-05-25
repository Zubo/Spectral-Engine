set(Stb_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/stb-install")
set(Stb_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/stb-download")
set(Stb_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/stb-source")

configure_file(StbDownload.in ${Stb_DOWNLOAD_DIR}/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${Stb_DOWNLOAD_DIR}")

if(result)
	message(FATAL_ERROR "CMake step for stb failed: ${result}")
endif()

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${Stb_DOWNLOAD_DIR}")

if(result)
	message(FATAL_ERROR "Build step for stb failed: ${result}")
endif()

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${Stb_INSTALL_DIR})