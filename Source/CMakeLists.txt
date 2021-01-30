cmake_minimum_required (VERSION 3.8)

include(CompileDefinitions.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(SpectralEditor)
add_subdirectory(ThirdParty)
add_subdirectory(PlatformIndependence)
add_subdirectory(Scene)
add_subdirectory(Core)
add_subdirectory(Render)
add_subdirectory(Test)

# TODO: Add tests and install targets if needed.
