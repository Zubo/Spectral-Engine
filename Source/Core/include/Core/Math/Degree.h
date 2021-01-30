#pragma once

#include "SpMath.h"

namespace sp {
	class Radian;

	class Degree {
	public:
		Degree();
		Degree(Degree const & degree) = default;
		Degree(SpFloat value);
		Degree(Radian radian);

	public:
		Degree operator/(SpFloat const value) const;

	public:
		SpFloat getValueDegrees() const {
			return _value;
		}

		SpFloat getValueRadians() const {
			return _value * PI / 180.0F;
		}

	private:
		SpFloat _value;
	};
}
