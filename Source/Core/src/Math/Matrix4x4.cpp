#include <algorithm>

#include <Core/Math/Matrix4x4.hpp>

namespace sp {
	Matrix4x4::Matrix4x4() : _values{ 0.0F } {
		_values[0][0] = 1.0F;
		_values[1][1] = 1.0F;
		_values[2][2] = 1.0F;
		_values[3][3] = 1.0F;
	}

	SpFloat * Matrix4x4::operator[](SpInt const ind) {
		return _values[ind];
	}

	SpFloat const * Matrix4x4::operator[](SpInt const ind) const {
		return _values[ind];
	}

	Matrix4x4 Matrix4x4::operator*(Matrix4x4 const & mat) const {
		Matrix4x4 resultMatrix;

		resultMatrix._values[0][0] = (_values[0][0] * mat[0][0]) + (_values[0][1] * mat[1][0]) + (_values[0][2] * mat[2][0]) + (_values[0][3] * mat[3][0]);
		resultMatrix._values[0][1] = (_values[0][0] * mat[0][1]) + (_values[0][1] * mat[1][1]) + (_values[0][2] * mat[2][1]) + (_values[0][3] * mat[3][1]);
		resultMatrix._values[0][2] = (_values[0][0] * mat[0][2]) + (_values[0][1] * mat[1][2]) + (_values[0][2] * mat[2][2]) + (_values[0][3] * mat[3][2]);
		resultMatrix._values[0][3] = (_values[0][0] * mat[0][3]) + (_values[0][1] * mat[1][3]) + (_values[0][2] * mat[2][3]) + (_values[0][3] * mat[3][3]);
		resultMatrix._values[1][0] = (_values[1][0] * mat[0][0]) + (_values[1][1] * mat[1][0]) + (_values[1][2] * mat[2][0]) + (_values[1][3] * mat[3][0]);
		resultMatrix._values[1][1] = (_values[1][0] * mat[0][1]) + (_values[1][1] * mat[1][1]) + (_values[1][2] * mat[2][1]) + (_values[1][3] * mat[3][1]);
		resultMatrix._values[1][2] = (_values[1][0] * mat[0][2]) + (_values[1][1] * mat[1][2]) + (_values[1][2] * mat[2][2]) + (_values[1][3] * mat[3][2]);
		resultMatrix._values[1][3] = (_values[1][0] * mat[0][3]) + (_values[1][1] * mat[1][3]) + (_values[1][2] * mat[2][3]) + (_values[1][3] * mat[3][3]);
		resultMatrix._values[2][0] = (_values[2][0] * mat[0][0]) + (_values[2][1] * mat[1][0]) + (_values[2][2] * mat[2][0]) + (_values[2][3] * mat[3][0]);
		resultMatrix._values[2][1] = (_values[2][0] * mat[0][1]) + (_values[2][1] * mat[1][1]) + (_values[2][2] * mat[2][1]) + (_values[2][3] * mat[3][1]);
		resultMatrix._values[2][2] = (_values[2][0] * mat[0][2]) + (_values[2][1] * mat[1][2]) + (_values[2][2] * mat[2][2]) + (_values[2][3] * mat[3][2]);
		resultMatrix._values[2][3] = (_values[2][0] * mat[0][3]) + (_values[2][1] * mat[1][3]) + (_values[2][2] * mat[2][3]) + (_values[2][3] * mat[3][3]);
		resultMatrix._values[3][0] = (_values[3][0] * mat[0][0]) + (_values[3][1] * mat[1][0]) + (_values[3][2] * mat[2][0]) + (_values[3][3] * mat[3][0]);
		resultMatrix._values[3][1] = (_values[3][0] * mat[0][1]) + (_values[3][1] * mat[1][1]) + (_values[3][2] * mat[2][1]) + (_values[3][3] * mat[3][1]);
		resultMatrix._values[3][2] = (_values[3][0] * mat[0][2]) + (_values[3][1] * mat[1][2]) + (_values[3][2] * mat[2][2]) + (_values[3][3] * mat[3][2]);
		resultMatrix._values[3][3] = (_values[3][0] * mat[0][3]) + (_values[3][1] * mat[1][3]) + (_values[3][2] * mat[2][3]) + (_values[3][3] * mat[3][3]);

		return resultMatrix;
	}

	SpFloat const * Matrix4x4::getValuePtr() const
	{
		return reinterpret_cast<SpFloat const *>(_values);
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
