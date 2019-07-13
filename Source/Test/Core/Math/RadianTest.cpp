#include "catch2/catch.hpp"
#include "Core/Math/Radian.h"
#include "Core/Math/SpMath.h"

namespace sp {
	namespace test {
		TEST_CASE("Radian/getValueRadian") {
			// Arrange
			float const initialValueRadian{ 2.12F };
			Radian const radian{ initialValueRadian };

			// Act
			float const resultValueRadians = radian.getValueRadians();

			// Assert
			REQUIRE(initialValueRadian == Approx(resultValueRadians));
		}

		TEST_CASE("Radian/getValueDegree") {
			// Arrange
			float const initialValueRadian{ 5.1F };
			Radian const radian{ initialValueRadian };

			// Act
			float const resultValueDegree = radian.getVlueDegrees();

			// Assert
			float const expectedValueDegree = initialValueRadian * 180.0F / PI;
			REQUIRE(expectedValueDegree == Approx(resultValueDegree));
		}
	}
}
