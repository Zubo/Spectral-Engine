set(SpectralEngine_PlatformIndependence_NoFilter_SRC
    "src/SpWindow.cpp"
    "src/Environment.cpp")

set(SpectralEngine_PlatformIndependence_NoFilter_HEADER
    "include/PlatformIndependence/SpWindow.hpp"
    "include/PlatformIndependence/SpString.hpp"
    "include/PlatformIndependence/SpType.hpp"
    "include/PlatformIndependence/SpHash.hpp"
    "include/PlatformIndependence/Environment.hpp")

set(SpectralEngine_PlatformIndependence_Input_SRC
    "src/Input/Input.cpp"
    "src/Input/KeyInputManager.cpp"
    "src/Input/MouseInputManager.cpp")

set(SpectralEngine_PlatformIndependence_Input_HEADER
    "include/PlatformIndependence/Input/Input.hpp"
    "include/PlatformIndependence/Input/KeyInputManager.hpp"
    "include/PlatformIndependence/Input/MouseInputManager.hpp"
    "include/PlatformIndependence/Input/KeyCode.hpp")

source_group("src" FILES ${SpectralEngine_PlatformIndependence_NoFilter_SRC})
source_group("include" FILES ${SpectralEngine_PlatformIndependence_NoFilter_HEADER})
source_group("src\\Input" FILES ${SpectralEngine_PlatformIndependence_Input_SRC})
source_group("include\\Input" FILES ${SpectralEngine_PlatformIndependence_Input_HEADER})

set(SpectralEngine_PlatformIndependence_SRC
    ${SpectralEngine_PlatformIndependence_NoFilter_SRC}
    ${SpectralEngine_PlatformIndependence_NoFilter_HEADER}
    ${SpectralEngine_PlatformIndependence_Input_SRC}
    ${SpectralEngine_PlatformIndependence_Input_HEADER})
