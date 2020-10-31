#include "Core/Math/Vector3.h"
#include "Core/Math/Vector2.h"
#include "Core/Math/SpMath.h"

namespace sp {
	SpFloat sp::Vector3::dot(Vector3 const & vec1, Vector3 const & vec2) {
		return (vec1.X * vec2.X) + (vec1.Y * vec2.Y) + (vec1.Z * vec2.Z);
	}

	Vector3 Vector3::cross(Vector3 const & vec1, Vector3 const & vec2) {
		return Vector3{
			(vec1.Y * vec2.Z) - (vec1.Z * vec2.Y),
			(vec1.Z * vec2.X) - (vec1.X * vec2.Z),
			(vec1.X * vec2.Y) - (vec1.Y * vec2.X)
		};
	}

	Vector3::Vector3() : X{ 0.0F }, Y{ 0.0F }, Z{ 0.0F } {

	}

	Vector3::Vector3(Vector2 const & vector) : X{ vector.X }, Y{ vector.Y }, Z{ 0.0F } {
	}

	Vector3::Vector3(SpFloat val) : X{ val }, Y{ val }, Z{ val } {
	}

	Vector3::Vector3 (SpFloat const x, SpFloat const y, SpFloat const z) : X{ x }, Y{ y }, Z{ z } {
	}

	Vector3 Vector3::operator-() const {
		return Vector3{ -X, -Y, -Z };
	}

	Vector3 Vector3::operator+(Vector3 const & vector) const {
		return Vector3{
			X + vector.X,
			Y + vector.Y,
			Z + vector.Z
		};
	}

	Vector3 Vector3::operator-(Vector3 const & vector) const {
		return Vector3{
			X - vector.X,
			Y - vector.Y,
			Z - vector.Z
		};
	}

	Vector3 Vector3::operator*(SpFloat const realNumber) const {
		return Vector3{
			X * realNumber,
			Y * realNumber,
			Z * realNumber
		};
	}

	Vector3 Vector3::operator+=(Vector3 const & vector) {
		*this = (*this) + vector;

		return *this;
	}

	Vector3 Vector3::operator-=(Vector3 const & vector) {
		*this = (*this) - vector;

		return *this;
	}

	Vector3 Vector3::normalized() const {
		SpFloat const vectorLength = length();

		return Vector3{
			X / vectorLength,
			Y / vectorLength,
			Z / vectorLength
		};
	}

	SpFloat Vector3::length() const {
		return sqrt((X * X) + (Y * Y) + (Z * Z));
	}

	Vector3 operator*(SpFloat const realNumber, Vector3 const & vector) {
		return Vector3{
			vector.X * realNumber,
			vector.Y * realNumber,
			vector.Z * realNumber
		};
	}
}
