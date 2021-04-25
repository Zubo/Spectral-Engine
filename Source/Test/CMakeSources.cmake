set(SpectralEngine_Test_Main
    "main.cpp")

set(SpectralEngine_Test_Core_Event_Source
    "Tests/Core/Event/EventBindingTest.cpp"
    "Tests/Core/Event/EventContextTest.cpp"
    "Tests/Core/Event/EventSubscriptionTest.cpp")
    
set(SpectralEngine_Test_Core_Event_Message_Source
    "Tests/Core/Event/Message/EventMessageTest.cpp")

set(SpectralEngine_Test_Core_Math_Source
    "Tests/Core/Math/DegreeTest.cpp"
    "Tests/Core/Math/LinearTransformationsTest.cpp"
    "Tests/Core/Math/Matrix4x4Test.cpp"
    "Tests/Core/Math/QuaternionTest.cpp"
    "Tests/Core/Math/RadianTest.cpp"
    "Tests/Core/Math/DegreeTest.cpp"
    "Tests/Core/Math/Vector3Test.cpp"
    "Tests/Core/Math/Vector2Test.cpp")

set(SpectralEngine_Test_Utility_Source
    "Tests/Core/Utility/StringConcatTest.cpp")

set(SpectralEngine_Mock_Core_Event
    "Mocks/Core/Event/IEventContextMock.hpp")

set(SpectralEngine_Test_Files
    "CMakeSources.cmake")

source_group("Tests\\Core\\Event" FILES ${SpectralEngine_Test_Core_Event_Source})
source_group("Tests\\Core\\Event\\Message" FILES ${SpectralEngine_Test_Core_Event_Message_Source})
source_group("Tests\\Core\\Math" FILES ${SpectralEngine_Test_Core_Math_Source})
source_group("Tests\\Core\\Utility" FILES ${SpectralEngine_Test_Utility_Source})
source_group("Mocks\\Core\\Event" FILES ${SpectralEngine_Mock_Core_Event})

set(SpectralEngine_Test_SRC
    ${SpectralEngine_Test_Main}
    ${SpectralEngine_Test_Core_Event_Source}
    ${SpectralEngine_Test_Core_Event_Message_Source}
    ${SpectralEngine_Test_Core_Math_Source}
    ${SpectralEngine_Test_Utility_Source}
    ${SpectralEngine_Test_Files}
    ${SpectralEngine_Mock_Core_Event})