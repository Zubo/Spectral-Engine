cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

enable_testing()

add_executable(Test ${SpectralEngine_Test_SRC})

target_link_libraries(Test Core)
target_link_libraries(Test gtest_main)

set_target_properties(Test PROPERTIES
    FOLDER Test)