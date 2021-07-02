cmake_minimum_required (VERSION 3.8)

include(CMakeSources.cmake)

add_library(Core STATIC "${Core_ALL_SRC}")
target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Core PRIVATE PlatformIndependence)

if(MSVC)
	target_compile_options(Core PRIVATE /W4 /WX)
else()
	target_compile_options(Core PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
