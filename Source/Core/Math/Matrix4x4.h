#pragma once

namespace sp {
	class Matrix4x4 {
	public:
		Matrix4x4();
		Matrix4x4(Matrix4x4 const & matrix) = default;

	public:
		float * operator[](int const ind);
		float const * operator[](int const ind) const;
		Matrix4x4 operator*(Matrix4x4 const & mat) const;

	public:
		float const * getValuePtr() const;
		Matrix4x4 const transposed() const;

	private:
		float values[4][4];
	};
}
