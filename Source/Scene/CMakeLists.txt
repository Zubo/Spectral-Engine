cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(Scene STATIC "${Scene_ALL_SRC}")
target_include_directories(Scene PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Scene PRIVATE Render)
target_link_libraries(Scene PRIVATE Core)
target_link_libraries(Scene PRIVATE PlatformIndependence)
target_link_libraries(Scene PRIVATE glad)
target_link_libraries(Scene PRIVATE khr)

if(MSVC)
	target_compile_options(Scene PRIVATE /W4 /WX)
else()
	target_compile_options(Scene PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
