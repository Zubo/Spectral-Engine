cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC "${SpectralEngine_Render_SRC}/include")

target_link_libraries(Render PRIVATE Core)

target_link_libraries(Render PRIVATE glad)
find_package(glfw3 REQUIRED)
target_link_libraries(Render PRIVATE glfw)
target_link_libraries(Render PRIVATE stb)
target_link_libraries(Render PRIVATE freetype)