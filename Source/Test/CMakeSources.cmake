set(SpectralEngine_Test_
	"main.cpp"
)

source_group("" FILES ${SpectralEngine_Test_})

set(SpectralEngine_Test_Mocks_Core_Event
	"Mocks/Core/Event/IEventContextMock.hpp"
)

source_group("Mocks/Core/Event" FILES ${SpectralEngine_Test_Mocks_Core_Event})

set(SpectralEngine_Test_Tests_Core_Assert
	"Tests/Core/Assert/SpAssertTest.cpp"
)

source_group("Tests/Core/Assert" FILES ${SpectralEngine_Test_Tests_Core_Assert})

set(SpectralEngine_Test_Tests_Core_Event
	"Tests/Core/Event/EventBindingTest.cpp"
	"Tests/Core/Event/EventContextTest.cpp"
	"Tests/Core/Event/EventSubscriptionTest.cpp"
)

source_group("Tests/Core/Event" FILES ${SpectralEngine_Test_Tests_Core_Event})

set(SpectralEngine_Test_Tests_Core_Event_Message
	"Tests/Core/Event/Message/EventMessageTest.cpp"
)

source_group("Tests/Core/Event/Message" FILES ${SpectralEngine_Test_Tests_Core_Event_Message})

set(SpectralEngine_Test_Tests_Core_Math
	"Tests/Core/Math/DegreeTest.cpp"
	"Tests/Core/Math/LinearTransformationsTest.cpp"
	"Tests/Core/Math/Matrix4x4Test.cpp"
	"Tests/Core/Math/QuaternionTest.cpp"
	"Tests/Core/Math/RadianTest.cpp"
	"Tests/Core/Math/SpMathTest.cpp"
	"Tests/Core/Math/SpMathUtilsTest.cpp"
	"Tests/Core/Math/Vector2Test.cpp"
	"Tests/Core/Math/Vector3Test.cpp"
)

source_group("Tests/Core/Math" FILES ${SpectralEngine_Test_Tests_Core_Math})

set(SpectralEngine_Test_Tests_Core_Utility
	"Tests/Core/Utility/StringConcatTest.cpp"
)

source_group("Tests/Core/Utility" FILES ${SpectralEngine_Test_Tests_Core_Utility})

set(Test_ALL_SRC
	${SpectralEngine_Test_}
	${SpectralEngine_Test_Mocks_Core_Event}
	${SpectralEngine_Test_Tests_Core_Assert}
	${SpectralEngine_Test_Tests_Core_Event}
	${SpectralEngine_Test_Tests_Core_Event_Message}
	${SpectralEngine_Test_Tests_Core_Math}
	${SpectralEngine_Test_Tests_Core_Utility}
)
