#include "Core/Math/Vector2.h"
#include "gtest/gtest.h"

namespace sp {
	namespace tests {
		TEST(Vector2, additionWithVector2) {
			// arrange
			SpFloat const firstX = 0.7F;
			SpFloat const secondX = 12.23F;
			SpFloat const firstY = 8.231F;
			SpFloat const secondY = 29312.2F;
			Vector2 const firstVector{ firstX, firstY };
			Vector2 const secondVector{ secondX, secondY };

			// act
			Vector2 const result = firstVector + secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.X, firstX + secondX);
			ASSERT_FLOAT_EQ(result.Y, firstY + secondY);
		}

		TEST(Vector2, subtractionWithVector2) {
			// arrange
			SpFloat const firstX = 0.7F;
			SpFloat const secondX = 12.23F;
			SpFloat const firstY = 8.231F;
			SpFloat const secondY = 29312.2F;
			Vector2 const firstVector{ firstX, firstY };
			Vector2 const secondVector{ secondX, secondY };

			// act
			Vector2 const result = firstVector - secondVector;

			// assert
			ASSERT_FLOAT_EQ(result.X, firstX - secondX);
			ASSERT_FLOAT_EQ(result.Y, firstY - secondY);
		}

		TEST(Vector2, negation) {
			// arrange
			SpFloat const x = 0.7F;
			SpFloat const y = 12.23F;
			Vector2 const vector{ x, y };

			// act
			Vector2 const result = -vector;

			// assert
			ASSERT_FLOAT_EQ(result.X, -x);
			ASSERT_FLOAT_EQ(result.Y, -y);
		}
	}
}
