cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC ${SpectralEngine_Render_SRC})

target_link_libraries(Render Glad_external)

find_package(glfw3 REQUIRED)
target_link_libraries(Render glfw)

target_link_libraries(Render STB_Image)


add_library(freetype STATIC IMPORTED)
set_property(TARGET freetype
	PROPERTY IMPORTED_LOCATION "${freetype_LIB_PATH}")
target_include_directories(freetype INTERFACE ${freetype_INCLUDE_PATH})

target_link_libraries(Render freetype)