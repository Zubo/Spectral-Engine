set(SpectralEngine_Core_include_Core_Assert
	"include/Core/Assert/SpAssert.hpp"
)

source_group("include/Core/Assert" FILES ${SpectralEngine_Core_include_Core_Assert})

set(SpectralEngine_Core_include_Core_Event
	"include/Core/Event/EventBinding.hpp"
	"include/Core/Event/EventContext.hpp"
	"include/Core/Event/EventSubscription.hpp"
	"include/Core/Event/IEventBinding.hpp"
	"include/Core/Event/IEventContext.hpp"
	"include/Core/Event/IEventSubscription.hpp"
)

source_group("include/Core/Event" FILES ${SpectralEngine_Core_include_Core_Event})

set(SpectralEngine_Core_include_Core_Event_Message
	"include/Core/Event/Message/EventMessage.hpp"
	"include/Core/Event/Message/EventMessageType.hpp"
)

source_group("include/Core/Event/Message" FILES ${SpectralEngine_Core_include_Core_Event_Message})

set(SpectralEngine_Core_include_Core_Event_Message_Messages
	"include/Core/Event/Message/Messages/ViewportChangedMessage.hpp"
)

source_group("include/Core/Event/Message/Messages" FILES ${SpectralEngine_Core_include_Core_Event_Message_Messages})

set(SpectralEngine_Core_include_Core_Exception
	"include/Core/Exception/SpException.hpp"
)

source_group("include/Core/Exception" FILES ${SpectralEngine_Core_include_Core_Exception})

set(SpectralEngine_Core_include_Core
	"include/Core/FileReader.hpp"
)

source_group("include/Core" FILES ${SpectralEngine_Core_include_Core})

set(SpectralEngine_Core_include_Core_Math
	"include/Core/Math/Degree.hpp"
	"include/Core/Math/Direction.hpp"
	"include/Core/Math/LinearTransformations.hpp"
	"include/Core/Math/Matrix4x4.hpp"
	"include/Core/Math/MatrixOperations.hpp"
	"include/Core/Math/Quaternion.hpp"
	"include/Core/Math/Radian.hpp"
	"include/Core/Math/SpMath.hpp"
	"include/Core/Math/Vector2.hpp"
	"include/Core/Math/Vector3.hpp"
)

source_group("include/Core/Math" FILES ${SpectralEngine_Core_include_Core_Math})

set(SpectralEngine_Core_include_Core_Utility
	"include/Core/Utility/OptionalRef.hpp"
	"include/Core/Utility/ResourcesPathProvider.hpp"
	"include/Core/Utility/StringConcat.hpp"
	"include/Core/Utility/WindowEventBinding.hpp"
)

source_group("include/Core/Utility" FILES ${SpectralEngine_Core_include_Core_Utility})

set(SpectralEngine_Core_src_Event
	"src/Event/EventBinding.cpp"
	"src/Event/EventContext.cpp"
	"src/Event/EventSubscription.cpp"
)

source_group("src/Event" FILES ${SpectralEngine_Core_src_Event})

set(SpectralEngine_Core_src_Event_Message
	"src/Event/Message/EventMessage.cpp"
)

source_group("src/Event/Message" FILES ${SpectralEngine_Core_src_Event_Message})

set(SpectralEngine_Core_src_Event_Message_Messages
	"src/Event/Message/Messages/ViewportChangedMessage.cpp"
)

source_group("src/Event/Message/Messages" FILES ${SpectralEngine_Core_src_Event_Message_Messages})

set(SpectralEngine_Core_src_Exception
	"src/Exception/SpException.cpp"
)

source_group("src/Exception" FILES ${SpectralEngine_Core_src_Exception})

set(SpectralEngine_Core_src
	"src/FileReader.cpp"
)

source_group("src" FILES ${SpectralEngine_Core_src})

set(SpectralEngine_Core_src_Math
	"src/Math/Degree.cpp"
	"src/Math/Direction.cpp"
	"src/Math/LinearTransformations.cpp"
	"src/Math/Matrix4x4.cpp"
	"src/Math/Quaternion.cpp"
	"src/Math/Radian.cpp"
	"src/Math/SpMath.cpp"
	"src/Math/Vector2.cpp"
	"src/Math/Vector3.cpp"
)

source_group("src/Math" FILES ${SpectralEngine_Core_src_Math})

set(SpectralEngine_Core_src_Utility
	"src/Utility/ResourcesPathProvider.cpp"
	"src/Utility/WindowEventBinding.cpp"
)

source_group("src/Utility" FILES ${SpectralEngine_Core_src_Utility})

set(Core_ALL_SRC
	${SpectralEngine_Core_include_Core_Assert}
	${SpectralEngine_Core_include_Core_Event}
	${SpectralEngine_Core_include_Core_Event_Message}
	${SpectralEngine_Core_include_Core_Event_Message_Messages}
	${SpectralEngine_Core_include_Core_Exception}
	${SpectralEngine_Core_include_Core}
	${SpectralEngine_Core_include_Core_Math}
	${SpectralEngine_Core_include_Core_Utility}
	${SpectralEngine_Core_src_Event}
	${SpectralEngine_Core_src_Event_Message}
	${SpectralEngine_Core_src_Event_Message_Messages}
	${SpectralEngine_Core_src_Exception}
	${SpectralEngine_Core_src}
	${SpectralEngine_Core_src_Math}
	${SpectralEngine_Core_src_Utility}
)
