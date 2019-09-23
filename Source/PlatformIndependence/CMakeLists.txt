cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(PlatformIndependence STATIC ${SpectralEngine_PlatformIndependence_SRC})

target_link_libraries(PlatformIndependence KHR)
target_link_libraries(PlatformIndependence GLFW)