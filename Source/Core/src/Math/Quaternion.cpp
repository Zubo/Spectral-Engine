#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"

namespace sp {
	Quaternion::Quaternion() : X{ 0.0F }, Y{ 0.0F }, Z{ 0.0F }, W{ 0.0F } {
	}

	Quaternion::Quaternion(SpFloat const x, SpFloat const y, SpFloat const z, SpFloat const w) : X{ x }, Y{ y }, Z{ z }, W{ w } {
	}

	Quaternion::Quaternion(Vector3 const & vec3) : X{ vec3.X }, Y{ vec3.Y }, Z{ vec3.Z }, W{ 0.0F } {
	}

	Quaternion Quaternion::operator*(Quaternion const & quat) const {
		return Quaternion{
			(X * quat.W) + (Y * quat.Z) - (Z * quat.Y) + (W * quat.X),
			-(X * quat.Z) + (Y * quat.W) + (Z * quat.X) + (W * quat.Y),
			(X * quat.Y) - (Y * quat.X) + (Z * quat.W) + (W * quat.Z),
			-(X * quat.X) - (Y * quat.Y) - (Z * quat.Z) + (W * quat.W)
		};
	}

	Quaternion Quaternion::operator*(Vector3 const & vec3) {
		return (*this) * Quaternion { vec3 };
	}

	Quaternion operator*(Vector3 const & vec3, Quaternion const & quat) {
		return Quaternion{ vec3 } * quat;
	}
}
