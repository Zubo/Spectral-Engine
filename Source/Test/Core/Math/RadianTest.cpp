#include "Core/Math/Radian.h"
#include "Core/Math/SpMath.h"
#include "gtest/gtest.h"

namespace sp {
	namespace test {
		TEST(Radian, getValueRadian) {
			// Arrange
			SpFloat const initialValueRadian{ 2.12F };
			Radian const radian{ initialValueRadian };

			// Act
			SpFloat const resultValueRadians = radian.getValueRadians();

			// Assert
			ASSERT_FLOAT_EQ(initialValueRadian, resultValueRadians);
		}

		TEST(Radian, getValueDegree) {
			// Arrange
			SpFloat const initialValueRadian{ 5.1F };
			Radian const radian{ initialValueRadian };

			// Act
			SpFloat const resultValueDegree = radian.getVlueDegrees();

			// Assert
			SpFloat const expectedValueDegree = initialValueRadian * 180.0F / PI;
			ASSERT_FLOAT_EQ(expectedValueDegree, resultValueDegree);
		}
	}
}
