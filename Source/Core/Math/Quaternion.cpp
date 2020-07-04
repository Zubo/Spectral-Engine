#include "Quaternion.h"
#include "Vector3.h"

namespace sp {
	Quaternion::Quaternion() : X{ 0.0F }, Y{ 0.0F }, Z{ 0.0F }, W{ 0.0F } {
	}

	Quaternion::Quaternion(SpFloat const x, SpFloat const y, SpFloat const z, SpFloat const w) : X{ x }, Y{ y }, Z{ z }, W{ w } {
	}

	Quaternion::Quaternion(Vector3 const & vec3) : X{ vec3.X }, Y{ vec3.Y }, Z{ vec3.Z }, W{ 0.0F } {
	}

	Quaternion Quaternion::operator*(Quaternion const & quat) const {
		return Quaternion{
			(this->X * quat.W) + (this->Y * quat.Z) - (this->Z * quat.Y) + (this->W * quat.X),
			-(this->X * quat.Z) + (this->Y * quat.W) + (this->Z * quat.X) + (this->W * quat.Y),
			(this->X * quat.Y) - (this->Y * quat.X) + (this->Z * quat.W) + (this->W * quat.Z),
			-(this->X * quat.X) - (this->Y * quat.Y) - (this->Z * quat.Z) + (this->W * quat.W)
		};
	}

	Quaternion Quaternion::operator*(Vector3 const & vec3) {
		return (*this) * Quaternion { vec3 };
	}

	Quaternion operator*(Vector3 const & vec3, Quaternion const & quat) {
		return Quaternion{ vec3 } * quat;
	}
}
