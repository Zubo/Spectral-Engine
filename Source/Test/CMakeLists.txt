cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

enable_testing()

add_executable(Test ${SpectralEngine_Test_SRC})

target_link_libraries(Test Core)
target_link_libraries(Test gtest_main)

set_target_properties(Test PROPERTIES
    FOLDER Test)

if(MSVC)
	target_compile_options(Test PRIVATE /W4 /WX)
else()
	target_compile_options(Test PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
