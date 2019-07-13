set(SpectralEngine_Test_Main
    "main.cpp")

set(SpectralEngine_Test_Core_Utility_Math_Source
    "Core/Math/DegreeTest.cpp"
    "Core/Math/LinearTransformationsTest.cpp"
    "Core/Math/Matrix4x4Test.cpp"
    "Core/Math/QuaternionTest.cpp"
    "Core/Math/RadianTest.cpp"
    "Core/Math/DegreeTest.cpp"
    "Core/Math/Vector3Test.cpp"
    "Core/Math/Vector2Test.cpp")

set(SpectralEngine_Test_Files
    "CMakeSources.cmake")

source_group("Core\\Math" FILES ${SpectralEngine_Test_Core_Utility_Math_Source})

set(SpectralEngine_Test_SRC
    ${SpectralEngine_Test_Main}
    ${SpectralEngine_Test_Core_Utility_Math_Source}
    ${SpectralEngine_Test_Files})