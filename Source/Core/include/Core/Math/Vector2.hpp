#pragma once

#include <Core/Math/Vector3.hpp>

namespace sp {
	class Vector2 {
	public:
		static Vector2 getVectorZero();
		static Vector2 getVectorOne();
	public:
		Vector2();
		Vector2(SpFloat const x, SpFloat const y);
		Vector2(Vector3 const & vector3);

	public:
		Vector2 operator+(Vector2 const & vector2) const;
		Vector2 operator-(Vector2 const & vector2) const;
		Vector2 operator-() const;
		Vector2 operator*(SpFloat const value) const;

	public:
		SpFloat X;
		SpFloat Y;
	};
}
