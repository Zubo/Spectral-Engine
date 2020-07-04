#pragma once

#include "PlatformIndependence/SpType.h"

namespace sp {
	class Vector2;

	class Vector3 {
	public:
		static SpFloat const dot(Vector3 const & vec1, Vector3 const & vec2);
		static Vector3 const cross(Vector3 const & vec1, Vector3 const & vec2);

	public:
		Vector3();
		Vector3(Vector3 const & vector) = default;
		Vector3(Vector2 const & vector);
		Vector3(SpFloat val);
		Vector3(SpFloat const x, SpFloat const y, SpFloat const z);

	public:
		SpFloat X, Y, Z;
		Vector3 operator-() const;
		Vector3 operator+(Vector3 const & vector) const;
		Vector3 operator-(Vector3 const & vector) const;
		Vector3 operator*(SpFloat const realNumber) const;
		Vector3 operator+=(Vector3 const & vector);
		Vector3 operator-=(Vector3 const & vector);

	public:
		Vector3 normalized() const;
		SpFloat const length() const;
	};

	Vector3 operator*(SpFloat const realNumber, Vector3 const & vector);
}
