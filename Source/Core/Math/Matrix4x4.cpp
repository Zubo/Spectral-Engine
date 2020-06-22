#include <algorithm>

#include "Core/Math/Matrix4x4.h"

namespace sp {
	Matrix4x4::Matrix4x4() : values{ 0.0F } {
		values[0][0] = 1.0F;
		values[1][1] = 1.0F;
		values[2][2] = 1.0F;
		values[3][3] = 1.0F;
	}

	float * Matrix4x4::operator[](SpInt const ind) {
		return values[ind];
	}

	float const * Matrix4x4::operator[](SpInt const ind) const {
		return values[ind];
	}

	Matrix4x4 Matrix4x4::operator*(Matrix4x4 const & mat) const {
		Matrix4x4 resultMatrix;

		resultMatrix.values[0][0] = (values[0][0] * mat[0][0]) + (values[0][1] * mat[1][0]) + (values[0][2] * mat[2][0]) + (values[0][3] * mat[3][0]);
		resultMatrix.values[0][1] = (values[0][0] * mat[0][1]) + (values[0][1] * mat[1][1]) + (values[0][2] * mat[2][1]) + (values[0][3] * mat[3][1]);
		resultMatrix.values[0][2] = (values[0][0] * mat[0][2]) + (values[0][1] * mat[1][2]) + (values[0][2] * mat[2][2]) + (values[0][3] * mat[3][2]);
		resultMatrix.values[0][3] = (values[0][0] * mat[0][3]) + (values[0][1] * mat[1][3]) + (values[0][2] * mat[2][3]) + (values[0][3] * mat[3][3]);
		resultMatrix.values[1][0] = (values[1][0] * mat[0][0]) + (values[1][1] * mat[1][0]) + (values[1][2] * mat[2][0]) + (values[1][3] * mat[3][0]);
		resultMatrix.values[1][1] = (values[1][0] * mat[0][1]) + (values[1][1] * mat[1][1]) + (values[1][2] * mat[2][1]) + (values[1][3] * mat[3][1]);
		resultMatrix.values[1][2] = (values[1][0] * mat[0][2]) + (values[1][1] * mat[1][2]) + (values[1][2] * mat[2][2]) + (values[1][3] * mat[3][2]);
		resultMatrix.values[1][3] = (values[1][0] * mat[0][3]) + (values[1][1] * mat[1][3]) + (values[1][2] * mat[2][3]) + (values[1][3] * mat[3][3]);
		resultMatrix.values[2][0] = (values[2][0] * mat[0][0]) + (values[2][1] * mat[1][0]) + (values[2][2] * mat[2][0]) + (values[2][3] * mat[3][0]);
		resultMatrix.values[2][1] = (values[2][0] * mat[0][1]) + (values[2][1] * mat[1][1]) + (values[2][2] * mat[2][1]) + (values[2][3] * mat[3][1]);
		resultMatrix.values[2][2] = (values[2][0] * mat[0][2]) + (values[2][1] * mat[1][2]) + (values[2][2] * mat[2][2]) + (values[2][3] * mat[3][2]);
		resultMatrix.values[2][3] = (values[2][0] * mat[0][3]) + (values[2][1] * mat[1][3]) + (values[2][2] * mat[2][3]) + (values[2][3] * mat[3][3]);
		resultMatrix.values[3][0] = (values[3][0] * mat[0][0]) + (values[3][1] * mat[1][0]) + (values[3][2] * mat[2][0]) + (values[3][3] * mat[3][0]);
		resultMatrix.values[3][1] = (values[3][0] * mat[0][1]) + (values[3][1] * mat[1][1]) + (values[3][2] * mat[2][1]) + (values[3][3] * mat[3][1]);
		resultMatrix.values[3][2] = (values[3][0] * mat[0][2]) + (values[3][1] * mat[1][2]) + (values[3][2] * mat[2][2]) + (values[3][3] * mat[3][2]);
		resultMatrix.values[3][3] = (values[3][0] * mat[0][3]) + (values[3][1] * mat[1][3]) + (values[3][2] * mat[2][3]) + (values[3][3] * mat[3][3]);

		return resultMatrix;
	}

	float const * Matrix4x4::getValuePtr() const
	{
		return reinterpret_cast<float const *>(values);
	}

	Matrix4x4 const Matrix4x4::transposed() const
	{
		Matrix4x4 result = (*this);
		for (SpInt i = 0; i < 3; ++i) {
			for (SpInt j = i + 1; j < 4; ++j) {
				std::swap(result[i][j], result[j][i]);
			}
		}

		return result;
	}
}
