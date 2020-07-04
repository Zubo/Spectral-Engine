#include "Core/Math/Vector3.h"
#include "gtest/gtest.h"

namespace sp {
	namespace test {
		TEST(Vector3, additionWithVector3) {
			// arrange
			SpFloat const firstX = 0.7F;
			SpFloat const secondX = 12.23F;
			SpFloat const firstY = 8.231F;
			SpFloat const secondY = 29312.2F;
			SpFloat const firstZ = -0.423F;
			SpFloat const secondZ = 203.23F;
			Vector3 const firstVector{ firstX, firstY, firstZ };
			Vector3 const secondVector{ secondX, secondY, secondZ };

			// act
			Vector3 const result = firstVector + secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.X, firstX + secondX);
			ASSERT_FLOAT_EQ(result.Y, firstY + secondY);
			ASSERT_FLOAT_EQ(result.Z, firstZ + secondZ);
		}

		TEST(Vector3, subtractionWithVector3) {
			// arrange
			SpFloat const firstX = 0.7F;
			SpFloat const secondX = 12.23F;
			SpFloat const firstY = 8.231F;
			SpFloat const secondY = 29312.2F;
			SpFloat const firstZ = 1.42F;
			SpFloat const secondZ = 30.0F;
			Vector3 const firstVector{ firstX, firstY, firstZ };
			Vector3 const secondVector{ secondX, secondY, secondZ };

			// act
			Vector3 const result = firstVector - secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.X, firstX - secondX);
			ASSERT_FLOAT_EQ(result.Y, firstY - secondY);
			ASSERT_FLOAT_EQ(result.Z, firstZ - secondZ);
		}

		TEST(Vector3, negation) {
			// arrange
			SpFloat const x = 0.7F;
			SpFloat const y = 12.23F;
			SpFloat const z = -14.23F;
			Vector3 const vector{ x, y, z };

			// act
			Vector3 const result = -vector;

			// assert
			ASSERT_FLOAT_EQ(result.X, -x);
			ASSERT_FLOAT_EQ(result.Y, -y);
			ASSERT_FLOAT_EQ(result.Z, -z);
		}
	}
}
