# CMakeList.txt : CMake project for SpectralEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include(CompileDefinitions.cmake)

# Add source to this project's executable.
add_executable (SpectralEditor "Main.cpp")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(ThirdParty)
add_subdirectory(PlatformIndependence)
add_subdirectory(Scene)
add_subdirectory(Core)
add_subdirectory(Render)
add_subdirectory(Test)

target_link_libraries(SpectralEditor PRIVATE Core)
target_link_libraries(SpectralEditor PRIVATE Render)
target_link_libraries(SpectralEditor PRIVATE Scene)
target_link_libraries(SpectralEditor PRIVATE PlatformIndependence)
target_link_libraries(SpectralEditor PRIVATE glad)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Binary/Build")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Binary/Build/lib")
# TODO: Add tests and install targets if needed.
