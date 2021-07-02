set(SpectralEngine_PlatformIndependence_include_PlatformIndependence
	"include/PlatformIndependence/Environment.hpp"
	"include/PlatformIndependence/SpHash.hpp"
	"include/PlatformIndependence/SpString.hpp"
	"include/PlatformIndependence/SpType.hpp"
	"include/PlatformIndependence/SpWindow.hpp"
)

source_group("include/PlatformIndependence" FILES ${SpectralEngine_PlatformIndependence_include_PlatformIndependence})

set(SpectralEngine_PlatformIndependence_include_PlatformIndependence_Input
	"include/PlatformIndependence/Input/Input.hpp"
	"include/PlatformIndependence/Input/KeyCode.hpp"
	"include/PlatformIndependence/Input/KeyInputManager.hpp"
	"include/PlatformIndependence/Input/MouseInputManager.hpp"
)

source_group("include/PlatformIndependence/Input" FILES ${SpectralEngine_PlatformIndependence_include_PlatformIndependence_Input})

set(SpectralEngine_PlatformIndependence_src
	"src/Environment.cpp"
	"src/SpWindow.cpp"
)

source_group("src" FILES ${SpectralEngine_PlatformIndependence_src})

set(SpectralEngine_PlatformIndependence_src_Input
	"src/Input/Input.cpp"
	"src/Input/KeyInputManager.cpp"
	"src/Input/MouseInputManager.cpp"
)

source_group("src/Input" FILES ${SpectralEngine_PlatformIndependence_src_Input})

set(PlatformIndependence_ALL_SRC
	${SpectralEngine_PlatformIndependence_include_PlatformIndependence}
	${SpectralEngine_PlatformIndependence_include_PlatformIndependence_Input}
	${SpectralEngine_PlatformIndependence_src}
	${SpectralEngine_PlatformIndependence_src_Input}
)
