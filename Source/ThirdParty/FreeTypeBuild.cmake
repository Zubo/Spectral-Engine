set(FreeType_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/FreeType-install")
set(FreeType_DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/FreeType-download")
message(STATUS "FreeType install dir is " ${FreeType_INSTALL_DIR})
configure_file(FreeTypeDownload.in ${FreeType_DOWNLOAD_DIR}/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${FreeType_DOWNLOAD_DIR})

if (result)
	message(FATAL_ERROR "CMake step for FreeType failed: ${result}")
endif()

execute_process(COMMAND "${CMAKE_COMMAND}" --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${FreeType_DOWNLOAD_DIR})

if (result)
	message(FATAL_ERROR "Build step for FreeType failed: ${result}")
endif()

# Add freetype library globally
set(freetype_LIB_PATH "${FreeType_INSTALL_DIR}/lib/freetyped.lib")
add_library(freetype STATIC IMPORTED GLOBAL)
set_property(TARGET freetype
	PROPERTY IMPORTED_LOCATION "${freetype_LIB_PATH}")

# Set include directories for freetype
set(freetype_INCLUDE_PATH "${FreeType_INSTALL_DIR}/include/freetype2/")
target_include_directories(freetype INTERFACE ${freetype_INCLUDE_PATH})