cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

enable_testing()

add_executable(Test ${SpectralEngine_Test_SRC})

# Catch:

set(Catch_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Catch)

include(ExternalProject)

ExternalProject_Add(catch_external
    PREFIX          ${Catch_INSTALL_DIR}
    GIT_REPOSITORY  https://github.com/catchorg/Catch2
    GIT_TAG         v2.7.2
    INSTALL_DIR     ${Catch_INSTALL_DIR}
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${Catch_INSTALL_DIR})

target_include_directories(Test PRIVATE ${Catch_INSTALL_DIR}/src/catch_external/single_include)

target_link_libraries(Test Core)

set_target_properties(Test PROPERTIES
    FOLDER Test)