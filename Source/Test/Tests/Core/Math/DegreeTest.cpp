#include "gtest/gtest.h"
#include "Core/Math/Degree.h"
#include "Core/Math/SpMath.h"


namespace sp
{
	namespace tests {
		TEST(DegreeTest, getValueDegree) {
			// Arrange
			SpFloat const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			SpFloat const resultValueDegree = degree.getValueDegrees();
			
			// Assert
			ASSERT_FLOAT_EQ(initialValueDegree, resultValueDegree);
		}

		TEST(DegreeTest, getValueRadian) {
			// Arrange
			SpFloat const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			SpFloat const resultValueRadians = degree.getValueRadians();

			// Assert
			SpFloat const expectedValueRadians = initialValueDegree * PI / 180.0F;
			ASSERT_FLOAT_EQ(expectedValueRadians, resultValueRadians);
		}
	}
}