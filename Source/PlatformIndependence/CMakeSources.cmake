set(SpectralEngine_PlatformIndependence_NoFilter_SRC
    "src/SpWindow.cpp"
    "src/Environment.cpp")

set(SpectralEngine_PlatformIndependence_NoFilter_HEADER
    "include/PlatformIndependence/SpWindow.h"
    "include/PlatformIndependence/SpString.h"
    "include/PlatformIndependence/SpType.h"
    "include/PlatformIndependence/SpHash.h"
    "include/PlatformIndependence/Environment.h")

set(SpectralEngine_PlatformIndependence_Input_SRC
    "src/Input/Input.cpp"
    "src/Input/KeyInputManager.cpp"
    "src/Input/MouseInputManager.cpp")

set(SpectralEngine_PlatformIndependence_Input_HEADER
    "include/PlatformIndependence/Input/Input.h"
    "include/PlatformIndependence/Input/KeyInputManager.h"
    "include/PlatformIndependence/Input/MouseInputManager.h"
    "include/PlatformIndependence/Input/KeyCode.h")

source_group("src" FILES ${SpectralEngine_PlatformIndependence_NoFilter_SRC})
source_group("include\\PlatformIndependence" FILES ${SpectralEngine_PlatformIndependence_NoFilter_HEADER})
source_group("src\\Input" FILES ${SpectralEngine_PlatformIndependence_Input_SRC})
source_group("include\\PlatformIndependence\\Input" FILES ${SpectralEngine_PlatformIndependence_Input_HEADER})

set(SpectralEngine_PlatformIndependence_SRC
    ${SpectralEngine_PlatformIndependence_NoFilter_SRC}
    ${SpectralEngine_PlatformIndependence_NoFilter_HEADER}
    ${SpectralEngine_PlatformIndependence_Input_SRC}
    ${SpectralEngine_PlatformIndependence_Input_HEADER})
