#include <Core/Math/Quaternion.h>
#include <Core/Math/Vector3.h>
#include <Core/Math/SpMath.h>
#include <gtest/gtest.h>

namespace sp {
	namespace tests {
		TEST(Quaternion, multiplicationWithQuat) {
			// arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// act
			Quaternion const result = (quat * Quaternion{ 0.4F, 1.0F, 0.0F, 12.2F });

			// assert
			Quaternion const expectedResult{ 1.4F, 137.66F, 23.88F, -10.1F };
			ASSERT_FLOAT_EQ(result.X, expectedResult.X);
			ASSERT_FLOAT_EQ(result.Y, expectedResult.Y);
			ASSERT_FLOAT_EQ(result.Z, expectedResult.Z);
			ASSERT_FLOAT_EQ(result.W, expectedResult.W);
		}


		TEST(Quaternion, multiplicationWithVec3) {
			// arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// act
			Quaternion const result = (quat * Vector3{ 0.4F, 1.0F, 1.2F });

			// assert
			Quaternion const expectedResult{ 11.18F, 0.66F, -4.06F, -14.08F };
			ASSERT_FLOAT_EQ(result.X, expectedResult.X);
			ASSERT_FLOAT_EQ(result.Y, expectedResult.Y);
			ASSERT_FLOAT_EQ(result.Z, expectedResult.Z);
			ASSERT_FLOAT_EQ(result.W, expectedResult.W);
		}
	}
}
