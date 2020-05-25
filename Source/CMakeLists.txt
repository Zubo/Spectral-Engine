# CMakeList.txt : CMake project for SpectralEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SpectralEngine "main.cpp")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(ThirdParty)
add_subdirectory(Game)
add_subdirectory(Core)
add_subdirectory(Render)
add_subdirectory(PlatformIndependence)
add_subdirectory(Test)

target_link_libraries(SpectralEngine Core)
target_link_libraries(SpectralEngine Game)
target_link_libraries(SpectralEngine glad)
target_link_libraries(SpectralEngine PlatformIndependence)

target_include_directories(Game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Render PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(PlatformIndependence PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Binary/Build")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Binary/Build/lib")
# TODO: Add tests and install targets if needed.
