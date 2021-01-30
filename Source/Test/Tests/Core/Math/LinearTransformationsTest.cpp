#include <gtest/gtest.h>
#include <Core/Math/LinearTransformations.h>
#include <Core/Math/Matrix4x4.h>
#include <Core/Math/Vector3.h>

namespace sp {
	namespace tests {
		TEST(LinearTransformations, translate) {
			// arrange
			Matrix4x4 transformation{};

			// act
			Vector3 const translation{ 2.5F, 1.0F, 18.231F };
			Matrix4x4 const resultMatrix = translate(transformation, translation);

			// assert
			for (SpInt i = 0; i < 16; ++i) {
				SpFloat expectedValue;
				switch (i)
				{
				case 3:
					expectedValue = translation.X;
					break;
				case 7:
					expectedValue = translation.Y;
					break;
				case 11:
					expectedValue = translation.Z;
					break;
				default:
					expectedValue = transformation.getValuePtr()[i];
					break;
				}

				SpFloat const * values = resultMatrix.getValuePtr();
				EXPECT_FLOAT_EQ(values[i], expectedValue);
			}
		}

		TEST(LinearTransformations, scale) {
			// arrange
			Matrix4x4 transformation{};

			// act
			Vector3 const scaleVector{ 2.5F, 1.0F, 18.231F };
			Matrix4x4 const resultMatrix = scale(transformation, scaleVector);

			// assert
			SpFloat const * startingValues = transformation.getValuePtr();
			for (SpInt i = 0; i < 16; ++i) {
				SpFloat expectedValue;

				switch (i)
				{
				case 0:
					expectedValue = startingValues[i] * scaleVector.X;
					break;
				case 5:
					expectedValue = startingValues[i] * scaleVector.Y;
					break;
				case 10:
					expectedValue = startingValues[i] * scaleVector.Z;
					break;
				default:
					expectedValue = transformation.getValuePtr()[i];
					break;
				}

				SpFloat const * resultValues = resultMatrix.getValuePtr();
				EXPECT_FLOAT_EQ(resultValues[i], expectedValue);
			}
		}
	}
}
