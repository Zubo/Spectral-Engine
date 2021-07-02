cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(PlatformIndependence STATIC "${PlatformIndependence_ALL_SRC}")
target_include_directories(PlatformIndependence PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(PlatformIndependence PRIVATE glad)
find_package(glfw3 REQUIRED)
target_link_libraries(PlatformIndependence PRIVATE glfw)
target_link_libraries(PlatformIndependence PRIVATE khr)

if(MSVC)
	target_compile_options(PlatformIndependence PRIVATE /W4 /WX)
else()
	target_compile_options(PlatformIndependence PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
