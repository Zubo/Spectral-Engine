#include <Core/Math/Radian.h>
#include <Core/Math/SpMath.h>
#include <gtest/gtest.h>

namespace sp {
	namespace tests {
		TEST(Radian, getValueRadian) {
			// arrange
			SpFloat const initialValueRadian{ 2.12F };
			Radian const radian{ initialValueRadian };

			// act
			SpFloat const resultValueRadians = radian.getValueRadians();

			// assert
			ASSERT_FLOAT_EQ(initialValueRadian, resultValueRadians);
		}

		TEST(Radian, getValueDegree) {
			// arrange
			SpFloat const initialValueRadian{ 5.1F };
			Radian const radian{ initialValueRadian };

			// act
			SpFloat const resultValueDegree = radian.getVlueDegrees();

			// assert
			SpFloat const expectedValueDegree = initialValueRadian * 180.0F / PI;
			ASSERT_FLOAT_EQ(expectedValueDegree, resultValueDegree);
		}
	}
}
