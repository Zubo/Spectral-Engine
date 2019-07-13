#include "catch2/catch.hpp"
#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"
#include "Core/Math/SpMath.h"

namespace sp {
	namespace test {
		TEST_CASE("Quaternion/multiplicationWithQuat") {
			// Arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// Act
			Quaternion const result = (quat * Quaternion{ 0.4F, 1.0F, 0.0F, 12.2F });

			// Assert
			Quaternion const expectedResult{ 1.4F, 137.66F, 23.88F, -10.1F };
			REQUIRE(result.x == Approx(expectedResult.x));
			REQUIRE(result.y == Approx(expectedResult.y));
			REQUIRE(result.z == Approx(expectedResult.z));
			REQUIRE(result.w == Approx(expectedResult.w));
		}


		TEST_CASE("Quaternion/multiplicationWithVec3") {
			// Arrange
			Quaternion const quat{ 0.3F, 11.2F, 2.3F, 0.1F };

			// Act
			Quaternion const result = (quat * Vector3{ 0.4F, 1.0F, 1.2F });

			// Assert
			Quaternion const expectedResult{ 11.18F, 0.66F, -4.06F, -14.08F };
			REQUIRE(result.x == Approx(expectedResult.x));
			REQUIRE(result.y == Approx(expectedResult.y));
			REQUIRE(result.z == Approx(expectedResult.z));
			REQUIRE(result.w == Approx(expectedResult.w));
		}
	}
}