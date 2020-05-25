set(KHR_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/khr-download")
set(KHR_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/khr-install")
configure_file(KhrDownload.in ${KHR_DOWNLOAD_DIR}/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${KHR_DOWNLOAD_DIR}")

if(result)
	message(FATAL_ERROR "CMake step for KHR failed: ${result}")
endif()

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${KHR_DOWNLOAD_DIR}")
	
if(result)
	message(FATAL_ERROR "Build step for KHR failed: ${result}")
endif()

add_library(khr INTERFACE)
target_include_directories(khr INTERFACE ${KHR_INSTALL_DIR})