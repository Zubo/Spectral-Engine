cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC "${Render_ALL_SRC}")
target_include_directories(Render PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Render PRIVATE Core)
target_link_libraries(Render PRIVATE PlatformIndependence)

target_link_libraries(Render PRIVATE glad)
target_link_libraries(Render PRIVATE stb)
target_link_libraries(Render PRIVATE freetype)

if(MSVC)
	target_compile_options(Render PRIVATE /W4 /WX)
else()
	target_compile_options(Render PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
