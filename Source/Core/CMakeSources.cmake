set(SpectralEngine_Core_NoFilter_SRC
	"FileReader.cpp")

set(SpectralEngine_Core_NoFilter_HEADER
	"FileReader.h")

set(SpectralEngine_Core_Utility_SRC
	"Utility/ResourcesPathProvider.cpp")

set(SpectralEngine_Core_Utility_HEADER
	"Utility/ResourcesPathProvider.h"
	"Utility/OptionalRef.h")

set(SpectralEngine_Core_Math_SRC
	"Math/SpMath.cpp"
	"Math/LinearTransformations.cpp"
	"Math/Radian.cpp"
	"Math/Degree.cpp"
	"Math/Vector3.cpp"
	"Math/Vector2.cpp"
	"Math/Quaternion.cpp"
	"Math/Matrix4x4.cpp"
	"Math/Direction.cpp")

set(SpectralEngine_Core_Math_HEADER
	"Math/SpMath.h"
	"Math/LinearTransformations.h"
	"Math/Radian.h"
	"Math/Degree.h"
	"Math/Vector3.h"
	"Math/Vector2.h"
	"Math/Quaternion.h"
	"Math/Matrix4x4.h"
	"Math/Direction.h")

set(SpectralEngine_Core_Event_HEADER
	"Event/EventContext.h"
	"Event/IEventContext.h"
	"Event/EventSubscription.h"
	"Event/IEventSubscription.h"
	"Event/EventBinding.h"
	"Event/IEventBinding.h")

set(SpectralEngine_Core_Event_SRC
	"Event/EventContext.cpp"
	"Event/EventSubscription.cpp"
	"Event/EventBinding.cpp")
	
set(SpectralEngine_Core_EventMessage_SRC
	"Event/Message/EventMessage.cpp")

set(SpectralEngine_Core_EventMessage_HEADER
	"Event/Message/EventMessage.h"
	"Event/Message/EventMessageType.h")

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
source_group("Source Files\\Event" FILES ${SpectralEngine_Core_Event_SRC})
source_group("Header Files\\Event" FILES ${SpectralEngine_Core_Event_HEADER})
source_group("Source Files\\Event\\Message" FILES ${SpectralEngine_Core_EventMessage_SRC})
source_group("Header Files\\Event\\Message" FILES ${SpectralEngine_Core_EventMessage_HEADER})

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
	${SpectralEngine_Core_Event_SRC}
	${SpectralEngine_Core_Event_HEADER}
	${SpectralEngine_Core_EventMessage_SRC}
	${SpectralEngine_Core_EventMessage_HEADER}
	${SpectralEngine_Core_Files})
