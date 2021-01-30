cmake_minimum_required (VERSION 3.8)
add_executable (SpectralEditor "src/Main.cpp")

target_link_libraries(SpectralEditor PRIVATE Core)
target_link_libraries(SpectralEditor PRIVATE Render)
target_link_libraries(SpectralEditor PRIVATE Scene)
target_link_libraries(SpectralEditor PRIVATE PlatformIndependence)
target_link_libraries(SpectralEditor PRIVATE glad)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Binary/Build")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Binary/Build/lib")