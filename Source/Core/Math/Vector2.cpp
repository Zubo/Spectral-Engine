#include "Vector2.h"

namespace sp {
	Vector2 Vector2::getVectorZero() {
		return Vector2{ 0.0F, 0.0F };
	}

	Vector2 Vector2::getVectorOne() {
		return Vector2{ 1.0F, 1.0F };
	}

	Vector2::Vector2() : x{ 0.0F }, y{ 0.0F } {
	}

	Vector2::Vector2(SpFloat const x, SpFloat const y) : x{ x }, y{ y } {
	}

	Vector2::Vector2(Vector3 const & vector3) : x{ vector3.x }, y{ vector3.y } {
	}

	Vector2 Vector2::operator+(Vector2 const & vector2) const {
		return Vector2{ this->x + vector2.x, this->y + vector2.y };
	}

	Vector2 Vector2::operator-(Vector2 const & vector2) const {
		return Vector2{ this->x - vector2.x, this->y - vector2.y };
	}

	Vector2 Vector2::operator-() const {
		return Vector2{ -this->x, -this->y };
	}

	Vector2 Vector2::operator*(SpFloat const value) const {
		return Vector2{ this->x * value, this->y * value };
	}
}
