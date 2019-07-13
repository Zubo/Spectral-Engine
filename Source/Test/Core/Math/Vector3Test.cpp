#include "catch2/catch.hpp"
#include "Core/Math/Vector3.h"

namespace sp {
	namespace test {
		TEST_CASE("Vector3/additionWithVector3") {
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
			REQUIRE(result.x == Approx(firstX + secondX));
			REQUIRE(result.y == Approx(firstY + secondY));
			REQUIRE(result.z == Approx(firstZ + secondZ));
		}

		TEST_CASE("Vector3/subtractionWithVector3") {
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
			REQUIRE(result.x == Approx(firstX - secondX));
			REQUIRE(result.y == Approx(firstY - secondY));
			REQUIRE(result.z == Approx(firstZ - secondZ));
		}

		TEST_CASE("Vector3/negation") {
			// arrange
			float const x = 0.7F;
			float const y = 12.23F;
			float const z = -14.23F;
			Vector3 const vector{ x, y, z };

			// act
			Vector3 const result = -vector;

			// assert
			REQUIRE(result.x == Approx (-x));
			REQUIRE(result.y == Approx(-y));
			REQUIRE(result.z == Approx(-z));
		}
	}
}
