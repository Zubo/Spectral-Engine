#include <Core/Math/Matrix4x4.hpp>
#include <gtest/gtest.h>

namespace sp {
	namespace tests {
		TEST(Matrix4x4, transpose) {
			// arrange
			Matrix4x4 mat;
			for (SpInt i = 0; i < 4; ++i) {
				for (SpInt j = 0; j < 4; ++j) {
					mat[i][j] = i * 10.0F + j;
				}
			}

			// act
			Matrix4x4 transposedMat = mat.transposed();

			// assert
			for (SpInt i = 0; i < 4; ++i) {
				for (SpInt j = 0; j < 4; ++j) {
					EXPECT_FLOAT_EQ(mat[i][j], transposedMat[j][i]);
				}
			}
		}
	}
}
