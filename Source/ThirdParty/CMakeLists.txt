cmake_minimum_required(VERSION 3.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# FreeType:
include(FreeTypeBuild.cmake)

# GLFW:
include(GlfwBuild.cmake)

#KHR
include(KhrBuild.cmake)

# Glad
add_subdirectory(Glad)

#STB_Image
include(StbBuild.cmake)
