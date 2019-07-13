#include "catch2/catch.hpp"
#include "Core/Math/Degree.h"
#include "Core/Math/SpMath.h"


namespace sp
{
	namespace test {
		TEST_CASE("DegreeTest/getValueDegree") {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueDegree = degree.getValueDegrees();
			
			// Assert
			REQUIRE(initialValueDegree == Approx(resultValueDegree));
		}

		TEST_CASE("DegreeTest/getValueRadian") {
			// Arrange
			float const initialValueDegree{ 50.0F };
			Degree const degree{ initialValueDegree };

			// Act
			float const resultValueRadians = degree.getValueRadians();

			// Assert
			float const expectedValueRadians = initialValueDegree * PI / 180.0F;
			REQUIRE(expectedValueRadians == Approx(resultValueRadians));
		}
	}
}