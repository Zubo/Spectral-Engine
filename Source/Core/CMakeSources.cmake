set(SpectralEngine_Core_NoFilter_SRC
	"FileReader.cpp")

set(SpectralEngine_Core_NoFilter_HEADER
	"FileReader.h")

set(SpectralEngine_Core_Utility_SRC
	"Utility/ResourcesPathProvider.cpp")

set(SpectralEngine_Core_Math_SRC
	"Math/SpMath.cpp"
	"Math/LinearTransformations.cpp"
	"Math/Radian.cpp"
	"Math/Degree.cpp"
	"Math/Vector3.cpp"
	"Math/Vector2.cpp"
	"Math/Quaternion.cpp"
	"Math/Matrix4x4.cpp")

set(SpectralEngine_Core_Math_HEADER
	"Math/SpMath.h"
	"Math/LinearTransformations.h"
	"Math/Radian.h"
	"Math/Degree.h"
	"Math/Vector3.h"
	"Math/Vector2.h"
	"Math/Quaternion.h"
	"Math/Matrix4x4.h")

set(SpectralEngine_Core_Utility_HEADER
	"Utility/ResourcesPathProvider.h")
	
set(SpectralEngine_Core_Files
	"CMakeSources.cmake")

source_group("Source Files" ${SpectralEngine_Core_NoFilter_SRC})
source_group("Header Files" ${SpectralEngine_Core_NoFilter_HEADER})
source_group("Source Files\\Utility" FILES ${SpectralEngine_Core_Utility_SRC})
source_group("Header Files\\Utility" FILES ${SpectralEngine_Core_Utility_HEADER})
source_group("Source Files\\Math" FILES ${SpectralEngine_Core_Math_SRC})
source_group("Header Files\\Math" FILES ${SpectralEngine_Core_Math_HEADER})
source_group("Source Files\\Utility\\Input" FILES ${SpectralEngine_Core_Input_SRC})
source_group("Header Files\\Utility\\Input" FILES ${SpectralEngine_Core_Input_HEADER})

set(SpectralEngine_Core_SRC
	${SpectralEngine_Core_Components_SRC}
	${SpectralEngine_Core_Components_HEADER}
	${SpectralEngine_Core_Components_Interface_HEADER}
	${SpectralEngine_Core_Components_UI_SRC}
	${SpectralEngine_Core_Components_UI_HEADER}
	${SpectralEngine_Core_NoFilter_SRC}
	${SpectralEngine_Core_NoFilter_HEADER}
	${SpectralEngine_Core_Utility_SRC}
	${SpectralEngine_Core_Utility_HEADER}
	${SpectralEngine_Core_Math_SRC}
	${SpectralEngine_Core_Math_HEADER}
	${SpectralEngine_Glad_SRC}
	${SpectralEngine_Core_Files})