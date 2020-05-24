cmake_minimum_required(VERSION 3.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# FreeType:
include(FreeTypeBuild.cmake)

# GLFW:
include(GlfwBuild.cmake)

# Glad
add_subdirectory(Glad)

#KHR
add_library(KHR INTERFACE)
target_include_directories(KHR INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/KHR)

#STB_Image
add_library(STB_Image INTERFACE)
target_include_directories(STB_Image INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/STB_Image/include)
