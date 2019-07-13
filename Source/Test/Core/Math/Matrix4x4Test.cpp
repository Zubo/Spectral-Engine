#include "Core/Math/Matrix4x4.h"
#include "catch2/catch.hpp"

namespace sp {
	namespace test {
		TEST_CASE("Matrix4x4/transpose") {
			// arrange
			Matrix4x4 mat;
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					mat[i][j] = i * 10 + j;
				}
			}

			// act
			Matrix4x4 transposedMat = mat.transposed();

			// assert
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					REQUIRE(mat[i][j] == Approx(transposedMat[j][i]));
				}
			}
		}
	}
}
