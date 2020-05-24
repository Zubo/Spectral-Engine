set(GLFW_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glfw-install")
set(GLFW_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/glfw-download")

configure_file(GlfwDownload.in ${GLFW_DOWNLOAD_DIR}/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${GLFW_DOWNLOAD_DIR}")

if(result)
	message(FATAL_ERROR "CMake step for glfw failed: ${result}")
endif()

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${GLFW_DOWNLOAD_DIR}")

if(result)
	message(FATAL_ERROR "Build step for glfw failed: ${result}")
endif()

# Enable finding glfw with find_package through whole project tree
set(glfw3_DIR "${GLFW_INSTALL_DIR}/lib/cmake/glfw3" CACHE STRING "Path to glfw package directory.")