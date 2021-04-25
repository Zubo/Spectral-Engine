set(SpectralEngine_Core_NoFilter_SRC
	"src/FileReader.cpp")

set(SpectralEngine_Core_NoFilter_HEADER
	"include/Core/FileReader.hpp")

set(SpectralEngine_Core_Utility_SRC
	"src/Utility/ResourcesPathProvider.cpp"
	"src/Utility/WindowEventBinding.cpp")

set(SpectralEngine_Core_Utility_HEADER
	"include/Core/Utility/ResourcesPathProvider.hpp"
	"include/Core/Utility/OptionalRef.hpp"
	"include/Core/Utility/WindowEventBinding.hpp"
	"include/Core/Utility/StringConcat.hpp")

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
	"include/Core/Math/SpMath.hpp"
	"include/Core/Math/LinearTransformations.hpp"
	"include/Core/Math/Radian.hpp"
	"include/Core/Math/Degree.hpp"
	"include/Core/Math/Vector3.hpp"
	"include/Core/Math/Vector2.hpp"
	"include/Core/Math/Quaternion.hpp"
	"include/Core/Math/Matrix4x4.hpp"
	"include/Core/Math/Direction.hpp")

set(SpectralEngine_Core_Event_HEADER
	"include/Core/Event/EventContext.hpp"
	"include/Core/Event/IEventContext.hpp"
	"include/Core/Event/EventSubscription.hpp"
	"include/Core/Event/IEventSubscription.hpp"
	"include/Core/Event/EventBinding.hpp"
	"include/Core/Event/IEventBinding.hpp")

set(SpectralEngine_Core_Event_SRC
	"src/Event/EventContext.cpp"
	"src/Event/EventSubscription.cpp"
	"src/Event/EventBinding.cpp")
	
set(SpectralEngine_Core_Exception_SRC
	"src/Exception/SpException.cpp")

set(SpectralEngine_Core_Exception_HEADER
	"include/Core/Exception/SpException.hpp")

set(SpectralEngine_Core_EventMessage_SRC
	"src/Event/Message/EventMessage.cpp")

set(SpectralEngine_Core_EventMessage_HEADER
	"include/Core/Event/Message/EventMessage.hpp"
	"include/Core/Event/Message/EventMessageType.hpp")
	
set(SpectralEngine_Core_EventMessage_Messages_SRC
	"src/Event/Message/Messages/ViewportChangedMessage.cpp")

set(SpectralEngine_Core_EventMessage_Messages_HEADER
	"include/Core/Event/Message/Messages/ViewportChangedMessage.hpp")

set(SpectralEngine_Core_Files
	"CMakeSources.cmake")

source_group("src" ${SpectralEngine_Core_NoFilter_SRC})
source_group("include\\Core" ${SpectralEngine_Core_NoFilter_HEADER})
source_group("src\\Utility" FILES ${SpectralEngine_Core_Utility_SRC})
source_group("include\\Core\\Utility" FILES ${SpectralEngine_Core_Utility_HEADER})
source_group("src\\Math" FILES ${SpectralEngine_Core_Math_SRC})
source_group("include\\Core\\Math" FILES ${SpectralEngine_Core_Math_HEADER})
source_group("src\\Exception" FILES ${SpectralEngine_Core_Exception_SRC})
source_group("include\\Core\\Exception" FILES ${SpectralEngine_Core_Exception_HEADER})
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
	${SpectralEngine_Core_Exception_SRC}
	${SpectralEngine_Core_Exception_HEADER}
	${SpectralEngine_Core_Event_SRC}
	${SpectralEngine_Core_Event_HEADER}
	${SpectralEngine_Core_EventMessage_SRC}
	${SpectralEngine_Core_EventMessage_HEADER}
	${SpectralEngine_Core_EventMessage_Messages_SRC}
	${SpectralEngine_Core_EventMessage_Messages_HEADER}
	${SpectralEngine_Core_Files})
