#include "Core/Math/Vector3.h"
#include "gtest/gtest.h"

namespace sp {
	namespace test {
		TEST(Vector3, additionWithVector3) {
			// arrange
			float const firstX = 0.7F;
			float const secondX = 12.23F;
			float const firstY = 8.231F;
			float const secondY = 29312.2F;
			float const firstZ = -0.423F;
			float const secondZ = 203.23F;
			Vector3 const firstVector{ firstX, firstY, firstZ };
			Vector3 const secondVector{ secondX, secondY, secondZ };

			// act
			Vector3 const result = firstVector + secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.x, firstX + secondX);
			ASSERT_FLOAT_EQ(result.y, firstY + secondY);
			ASSERT_FLOAT_EQ(result.z, firstZ + secondZ);
		}

		TEST(Vector3, subtractionWithVector3) {
			// arrange
			float const firstX = 0.7F;
			float const secondX = 12.23F;
			float const firstY = 8.231F;
			float const secondY = 29312.2F;
			float const firstZ = 1.42F;
			float const secondZ = 30.0F;
			Vector3 const firstVector{ firstX, firstY, firstZ };
			Vector3 const secondVector{ secondX, secondY, secondZ };

			// act
			Vector3 const result = firstVector - secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.x, firstX - secondX);
			ASSERT_FLOAT_EQ(result.y, firstY - secondY);
			ASSERT_FLOAT_EQ(result.z, firstZ - secondZ);
		}

		TEST(Vector3, negation) {
			// arrange
			float const x = 0.7F;
			float const y = 12.23F;
			float const z = -14.23F;
			Vector3 const vector{ x, y, z };

			// act
			Vector3 const result = -vector;

			// assert
			ASSERT_FLOAT_EQ(result.x, -x);
			ASSERT_FLOAT_EQ(result.y, -y);
			ASSERT_FLOAT_EQ(result.z, -z);
		}
	}
}
