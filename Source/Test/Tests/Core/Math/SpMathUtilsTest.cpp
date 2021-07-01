#include <Core/Math/SpMathUtils.hpp>
#include <gtest/gtest.h>

namespace sp {
	namespace tests {
		TEST(SpMathUtils, IsPointInBox_OutByNegativeX) {
			// Arrange
			Vector2 const point{ -0.2F, 0.5F };
			Vector2 const boxOrigin{ 0.0F, 0.0F };
			Vector2 const boxSize{ 1.0F, 1.0F };

			// Act
			bool const result{ isPointInBox(point, boxOrigin, boxSize) };

			// Assert
			ASSERT_FALSE(result);
		}

		TEST(SpMathUtils, IsPointInBox_OutByPositiveX) {
			// Arrange
			Vector2 const point{ 1.2F, 0.5F };
			Vector2 const boxOrigin{ 0.0F, 0.0F };
			Vector2 const boxSize{ 1.0F, 1.0F };

			// Act
			bool const result{ isPointInBox(point, boxOrigin, boxSize) };

			// Assert
			ASSERT_FALSE(result);
		}

		TEST(SpMathUtils, IsPointInBox_OutByNegativeY) {
			// Arrange
			Vector2 const point{ 0.5F, -0.2F };
			Vector2 const boxOrigin{ 0.0F, 0.0F };
			Vector2 const boxSize{ 1.0F, 1.0F };

			// Act
			bool const result{ isPointInBox(point, boxOrigin, boxSize) };

			// Assert
			ASSERT_FALSE(result);
		}

		TEST(SpMathUtils, IsPointInBox_OutByPositiveY) {
			// Arrange
			Vector2 const point{ 0.5F, 1.2F };
			Vector2 const boxOrigin{ 0.0F, 0.0F };
			Vector2 const boxSize{ 1.0F, 1.0F };

			// Act
			bool const result{ isPointInBox(point, boxOrigin, boxSize) };

			// Assert
			ASSERT_FALSE(result);
		}

		TEST(SpMathUtils, IsPointIntBox_IsInside) {
			// Arrange
			Vector2 const point{ 0.5F, 0.5F };
			Vector2 const boxOrigin{ 0.0F, 0.0F };
			Vector2 const boxSize{ 1.0F, 1.0F };

			// Act
			bool const result{ isPointInBox(point, boxOrigin, boxSize) };

			// Assert
			ASSERT_TRUE(result);
		}
	}
}