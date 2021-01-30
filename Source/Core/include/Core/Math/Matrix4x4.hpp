#pragma once

#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class Matrix4x4 {
	public:
		Matrix4x4();
		Matrix4x4(Matrix4x4 const & matrix) = default;

	public:
		SpFloat * operator[](SpInt const ind);
		SpFloat const * operator[](SpInt const ind) const;
		Matrix4x4 operator*(Matrix4x4 const & mat) const;

	public:
		SpFloat const * getValuePtr() const;
		Matrix4x4 const transposed() const;

	private:
		SpFloat _values[4][4];
	};
}
