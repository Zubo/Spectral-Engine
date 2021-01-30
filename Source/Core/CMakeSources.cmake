set(SpectralEngine_Core_NoFilter_SRC
	"FileReader.cpp")

set(SpectralEngine_Core_NoFilter_HEADER
	"include/Core/FileReader.h")

set(SpectralEngine_Core_Utility_SRC
	"src/Utility/ResourcesPathProvider.cpp"
	"src/Utility/WindowEventBinding.cpp")

set(SpectralEngine_Core_Utility_HEADER
	"include/Core/Utility/ResourcesPathProvider.h"
	"include/Core/Utility/OptionalRef.h"
	"include/Core/Utility/WindowEventBinding.h")

set(SpectralEngine_Core_Math_SRC
	"src/Math/SpMath.cpp"
	"src/Math/LinearTransformations.cpp"
	"src/Math/Radian.cpp"
	"src/Math/Degree.cpp"
	"src/Math/Vector3.cpp"
	"src/Math/Vector2.cpp"
	"src/Math/Quaternion.cpp"
	"src/Math/Matrix4x4.cpp"
	"src/Math/Direction.cpp")

set(SpectralEngine_Core_Math_HEADER
	"include/Core/Math/SpMath.h"
	"include/Core/Math/LinearTransformations.h"
	"include/Core/Math/Radian.h"
	"include/Core/Math/Degree.h"
	"include/Core/Math/Vector3.h"
	"include/Core/Math/Vector2.h"
	"include/Core/Math/Quaternion.h"
	"include/Core/Math/Matrix4x4.h"
	"include/Core/Math/Direction.h")

set(SpectralEngine_Core_Event_HEADER
	"include/Core/Event/EventContext.h"
	"include/Core/Event/IEventContext.h"
	"include/Core/Event/EventSubscription.h"
	"include/Core/Event/IEventSubscription.h"
	"include/Core/Event/EventBinding.h"
	"include/Core/Event/IEventBinding.h")

set(SpectralEngine_Core_Event_SRC
	"src/Event/EventContext.cpp"
	"src/Event/EventSubscription.cpp"
	"src/Event/EventBinding.cpp")
	
set(SpectralEngine_Core_EventMessage_SRC
	"src/Event/Message/EventMessage.cpp")

set(SpectralEngine_Core_EventMessage_HEADER
	"include/Core/Event/Message/EventMessage.h"
	"include/Core/Event/Message/EventMessageType.h")
	
set(SpectralEngine_Core_EventMessage_Messages_SRC
	"Event/Message/Messages/ViewportChangedMessage.cpp")

set(SpectralEngine_Core_EventMessage_Messages_HEADER
	"include/Core/Event/Message/Messages/ViewportChangedMessage.h")

set(SpectralEngine_Core_Files
	"CMakeSources.cmake")

source_group("src" ${SpectralEngine_Core_NoFilter_SRC})
source_group("include\\Core" ${SpectralEngine_Core_NoFilter_HEADER})
source_group("src\\Utility" FILES ${SpectralEngine_Core_Utility_SRC})
source_group("include\\Core\\Utility" FILES ${SpectralEngine_Core_Utility_HEADER})
source_group("src\\Math" FILES ${SpectralEngine_Core_Math_SRC})
source_group("include\\Core\\Math" FILES ${SpectralEngine_Core_Math_HEADER})
source_group("src\\Utility\\Input" FILES ${SpectralEngine_Core_Input_SRC})
source_group("include\\Core\\Utility\\Input" FILES ${SpectralEngine_Core_Input_HEADER})
source_group("src\\Event" FILES ${SpectralEngine_Core_Event_SRC})
source_group("include\\Core\\Event" FILES ${SpectralEngine_Core_Event_HEADER})
source_group("src\\Event\\Message" FILES ${SpectralEngine_Core_EventMessage_SRC})
source_group("include\\Core\\Event\\Message" FILES ${SpectralEngine_Core_EventMessage_HEADER})
source_group("src\\Event\\Message\\Messages" FILES ${SpectralEngine_Core_EventMessage_Messages_SRC})
source_group("include\\Core\\Event\\Message\\Messages" FILES ${SpectralEngine_Core_EventMessage_Messages_HEADER})

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
	${SpectralEngine_Core_EventMessage_Messages_SRC}
	${SpectralEngine_Core_EventMessage_Messages_HEADER}
	${SpectralEngine_Core_Files})
