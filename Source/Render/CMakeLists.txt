cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)
include(CopyShaderFiles.cmake)

add_library(Render STATIC ${SpectralEngine_Render_SRC})

target_link_libraries(Render Glad_external)
target_link_libraries(Render FreeType)
target_link_libraries(Render GLFW)
target_link_libraries(Render STB_Image)