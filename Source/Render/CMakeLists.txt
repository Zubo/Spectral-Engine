cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC ${SpectralEngine_Render_SRC})

target_link_libraries(Render glad)

find_package(glfw3 REQUIRED)
target_link_libraries(Render glfw)

target_link_libraries(Render stb)

target_link_libraries(Render freetype)