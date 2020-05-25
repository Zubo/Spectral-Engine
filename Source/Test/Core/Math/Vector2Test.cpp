#include "Core/Math/Vector2.h"
#include "gtest/gtest.h"

namespace sp {
	namespace test {
		TEST(Vector2, additionWithVector2) {
			// arrange
			float const firstX = 0.7F;
			float const secondX = 12.23F;
			float const firstY = 8.231F;
			float const secondY = 29312.2F;
			Vector2 const firstVector{ firstX, firstY };
			Vector2 const secondVector{ secondX, secondY };
			
			// act
			Vector2 const result = firstVector + secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.x, firstX + secondX);
			ASSERT_FLOAT_EQ(result.y, firstY + secondY);
		}

		TEST(Vector2, subtractionWithVector2) {
			// arrange
			float const firstX = 0.7F;
			float const secondX = 12.23F;
			float const firstY = 8.231F;
			float const secondY = 29312.2F;
			Vector2 const firstVector{ firstX, firstY };
			Vector2 const secondVector{ secondX, secondY };

			// act
			Vector2 const result = firstVector - secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.x, firstX - secondX);
			ASSERT_FLOAT_EQ(result.y, firstY - secondY);
		}

		TEST(Vector2, negation) {
			// arrange
			float const x = 0.7F;
			float const y = 12.23F;
			Vector2 const vector{ x, y };

			// act
			Vector2 const result = -vector;

			// assert
			ASSERT_FLOAT_EQ(result.x, -x);
			ASSERT_FLOAT_EQ(result.y, -y);
		}
	}
}
