cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(PlatformIndependence STATIC ${SpectralEngine_PlatformIndependence_SRC})

target_link_libraries(PlatformIndependence KHR)

find_package(glfw3 REQUIRED)
target_link_libraries(PlatformIndependence glfw)