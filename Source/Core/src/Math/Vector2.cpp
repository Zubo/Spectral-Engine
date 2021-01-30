#include "Vector2.h"

namespace sp {
	Vector2 Vector2::getVectorZero() {
		return Vector2{ 0.0F, 0.0F };
	}

	Vector2 Vector2::getVectorOne() {
		return Vector2{ 1.0F, 1.0F };
	}

	Vector2::Vector2() : X{ 0.0F }, Y{ 0.0F } {
	}

	Vector2::Vector2(SpFloat const x, SpFloat const y) : X{ x }, Y{ y } {
	}

	Vector2::Vector2(Vector3 const & vector3) : X{ vector3.X }, Y{ vector3.Y } {
	}

	Vector2 Vector2::operator+(Vector2 const & vector2) const {
		return Vector2{ X + vector2.X, Y + vector2.Y };
	}

	Vector2 Vector2::operator-(Vector2 const & vector2) const {
		return Vector2{ X - vector2.X, Y - vector2.Y };
	}

	Vector2 Vector2::operator-() const {
		return Vector2{ -X, -Y };
	}

	Vector2 Vector2::operator*(SpFloat const value) const {
		return Vector2{ X * value, Y * value };
	}
}
