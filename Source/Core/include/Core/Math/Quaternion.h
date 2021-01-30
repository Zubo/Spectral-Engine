#pragma once

#include <PlatformIndependence/SpType.h>

namespace sp {
	class Vector3;

	class Quaternion {
		friend Quaternion operator*(Vector3 const & vec, Quaternion const & quat);

	public:
		Quaternion();
		Quaternion(Quaternion const & quaternion) = default;
		Quaternion(SpFloat const x, SpFloat const y, SpFloat const z, SpFloat const w);
		Quaternion(Vector3 const & vec3);

	public:
		Quaternion operator*(Quaternion const & quaternion) const;
		Quaternion operator*(Vector3 const & vec3);

	public:
		SpFloat const X, Y, Z, W;
	};
}
