#include "catch2/catch.hpp"
#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"

namespace sp {
	namespace test {
		TEST_CASE("LinearTransformations/translate") {
			// arrange
			Matrix4x4 transformation{};

			// act
			Vector3 const translation{ 2.5F, 1.0F, 18.231F };
			Matrix4x4 const resultMatrix = translate(transformation, translation);

			// assert
			for (int i = 0; i < 16; ++i) {
				float expectedValue;
				switch (i)
				{
				case 3:
					expectedValue = translation.x;
					break;
				case 7:
					expectedValue = translation.y;
					break;
				case 11:
					expectedValue = translation.z;
					break;
				default:
					expectedValue = transformation.getValuePtr()[i];
					break;
				}

				float const * values = resultMatrix.getValuePtr();
				REQUIRE(values[i] == Approx(expectedValue));
			}
		}

		TEST_CASE("LinearTransformations/scale") {
			// arrange
			Matrix4x4 transformation{};

			// act
			Vector3 const scaleVector{ 2.5F, 1.0F, 18.231F };
			Matrix4x4 const resultMatrix = scale(transformation, scaleVector);

			// assert
			float const * startingValues = transformation.getValuePtr();
			for (int i = 0; i < 16; ++i) {
				float expectedValue;

				switch (i)
				{
				case 0:
					expectedValue = startingValues[i] * scaleVector.x;
					break;
				case 5:
					expectedValue = startingValues[i] * scaleVector.y;
					break;
				case 10:
					expectedValue = startingValues[i] * scaleVector.z;
					break;
				default:
					expectedValue = transformation.getValuePtr()[i];
					break;
				}

				float const * resultValues = resultMatrix.getValuePtr();
				REQUIRE(resultValues[i] == Approx(expectedValue));
			}
		}
	}
}