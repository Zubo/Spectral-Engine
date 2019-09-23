cmake_minimum_required(VERSION 3.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
include(ExternalProject)

# FreeType:
set(FreeType_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FreeType)

ExternalProject_Add(FreeType_download
    PREFIX          ${FreeType_INSTALL_DIR}
    GIT_REPOSITORY  https://github.com/aseprite/freetype2
    GIT_TAG         VER-2-8-1
    UPDATE_COMMAND  ""
    INSTALL_DIR     ${FreeType_INSTALL_DIR}
    CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX=${FreeType_INSTALL_DIR})

add_library(FreeType STATIC IMPORTED GLOBAL)
set_target_properties(FreeType PROPERTIES
    IMPORTED_LOCATION ${FreeType_INSTALL_DIR}/lib/freetyped.lib)
target_include_directories(FreeType INTERFACE ${FreeType_INSTALL_DIR}/include/freetype2)

# GLFW:
set(GLFW_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLFW)

ExternalProject_Add(glfw_download
    PREFIX         ${GLFW_INSTALL_DIR}
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.2.1
    UPDATE_COMMAND ""
    INSTALL_DIR    ${GLFW_INSTALL_DIR}
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${GLFW_INSTALL_DIR})

add_library(GLFW STATIC IMPORTED GLOBAL)
set_target_properties(GLFW PROPERTIES
    IMPORTED_LOCATION ${GLFW_INSTALL_DIR}/lib/glfw3.lib)
target_include_directories(GLFW INTERFACE ${GLFW_INSTALL_DIR}/include)

# Glad
add_subdirectory(Glad)

#KHR
add_library(KHR INTERFACE)
target_include_directories(KHR INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/KHR)

#STB_Image
add_library(STB_Image INTERFACE)
target_include_directories(STB_Image INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/STB_Image/include)
