#include "Core/Math/Matrix4x4.h"
#include "gtest/gtest.h"

namespace sp {
	namespace test {
		TEST(Matrix4x4, transpose) {
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
					EXPECT_FLOAT_EQ(mat[i][j], transposedMat[j][i]);
				}
			}
		}
	}
}
