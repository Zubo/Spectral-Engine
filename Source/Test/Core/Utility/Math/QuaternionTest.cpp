#include "gtest/gtest.h"
#include "Utility/Math/Quaternion.h"
#include "Utility/Math/Vector3.h"
#include "Utility/Math/SpMath.h"

namespace sp {
	namespace test {
		TEST(Quaternion, multiplicationWithQuat) {
			// Arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// Act
			Quaternion const result = (quat * Quaternion{ 0.4F, 1.0F, 0.0F, 12.2F });

			// Assert
			Quaternion const expectedResult{ 1.4F, 137.66F, 23.88F, -10.1F };
			ASSERT_FLOAT_EQ(result.x, expectedResult.x);
			ASSERT_FLOAT_EQ(result.y, expectedResult.y);
			ASSERT_FLOAT_EQ(result.z, expectedResult.z);
			ASSERT_FLOAT_EQ(result.w, expectedResult.w);
		}


		TEST(Quaternion, multiplicationWithVec3) {
			// Arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// Act
			Quaternion const result = (quat * Vector3{ 0.4F, 1.0F, 1.2F });

			// Assert
			Quaternion const expectedResult{ 11.18F, 0.66F, -4.06F, -14.08F };
			ASSERT_FLOAT_EQ(result.x, expectedResult.x);
			ASSERT_FLOAT_EQ(result.y, expectedResult.y);
			ASSERT_FLOAT_EQ(result.z, expectedResult.z);
			ASSERT_FLOAT_EQ(result.w, expectedResult.w);
		}
	}
}