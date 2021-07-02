cmake_minimum_required(VERSION 3.8)

include(CMakeSources.cmake)

add_library(glad STATIC ${Glad_ALL_SRC})
target_include_directories(glad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

set_target_properties(glad PROPERTIES
    FOLDER ThirdParty)

target_link_libraries(glad khr)