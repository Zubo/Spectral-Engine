set(Gtest_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/gtest-build")
set(Gtest_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/gtest-src")
set(Gtest_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/gtest-download")

configure_file(GtestDownload.in "${Gtest_DOWNLOAD_DIR}/CMakeLists.txt")

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${Gtest_DOWNLOAD_DIR}")

if (result)
	message(FATAL_ERROR "CMake step for gtest failed: ${result}")
endif()

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY "${Gtest_DOWNLOAD_DIR}")
	
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${Gtest_SOURCE_DIR}
                 ${Gtest_BUILD_DIR}
                 EXCLUDE_FROM_ALL)

set_target_properties(gtest PROPERTIES
	FOLDER ThirdParty)
set_target_properties(gtest_main PROPERTIES
	FOLDER ThirdParty)
