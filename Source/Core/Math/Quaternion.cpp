#include "Quaternion.h"
#include "Vector3.h"

namespace sp {
	Quaternion::Quaternion() : x{ 0.0F }, y{ 0.0F }, z{ 0.0F }, w{ 0.0F } {
	}

	Quaternion::Quaternion(SpFloat const x, SpFloat const y, SpFloat const z, SpFloat const w) : x{ x }, y{ y }, z{ z }, w{ w } {
	}

	Quaternion::Quaternion(Vector3 const & vec3) : x{ vec3.x }, y{ vec3.y }, z{ vec3.z }, w{ 0.0F } {
	}

	Quaternion Quaternion::operator*(Quaternion const & quat) const {
		return Quaternion{
			(this->x * quat.w) + (this->y * quat.z) - (this->z * quat.y) + (this->w * quat.x),
			-(this->x * quat.z) + (this->y * quat.w) + (this->z * quat.x) + (this->w * quat.y),
			(this->x * quat.y) - (this->y * quat.x) + (this->z * quat.w) + (this->w * quat.z),
			-(this->x * quat.x) - (this->y * quat.y) - (this->z * quat.z) + (this->w * quat.w)
		};
	}

	Quaternion Quaternion::operator*(Vector3 const & vec3) {
		return (*this) * Quaternion { vec3 };
	}

	Quaternion operator*(Vector3 const & vec3, Quaternion const & quat) {
		return Quaternion{ vec3 } * quat;
	}
}