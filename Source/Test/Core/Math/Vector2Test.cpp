#include "catch2/catch.hpp"
#include "Core/Math/Vector2.h"

namespace sp {
	namespace test {
		TEST_CASE("Vector2/additionWithVector2") {
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
			REQUIRE(result.x == Approx(firstX + secondX));
			REQUIRE(result.y == Approx(firstY + secondY));
		}

		TEST_CASE("Vector2/subtractionWithVector2") {
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
			REQUIRE(result.x == Approx(firstX - secondX));
			REQUIRE(result.y == Approx(firstY - secondY));
		}

		TEST_CASE("Vector2/negation") {
			// arrange
			float const x = 0.7F;
			float const y = 12.23F;
			Vector2 const vector{ x, y };

			// act
			Vector2 const result = -vector;

			// assert
			REQUIRE(result.x == Approx(-x));
			REQUIRE(result.y == Approx(-y));
		}
	}
}
