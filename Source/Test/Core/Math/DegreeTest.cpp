#include "gtest/gtest.h"
#include "Core/Math/Degree.h"
#include "Core/Math/SpMath.h"


namespace sp
{
	namespace test {
		TEST(DegreeTest, getValueDegree) {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueDegree = degree.getValueDegrees();
			
			// Assert
			ASSERT_FLOAT_EQ(initialValueDegree, resultValueDegree);
		}

		TEST(DegreeTest, getValueRadian) {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueRadians = degree.getValueRadians();

			// Assert
			float const expectedValueRadians = initialValueDegree * PI / 180.0F;
			ASSERT_FLOAT_EQ(expectedValueRadians, resultValueRadians);
		}
	}
}