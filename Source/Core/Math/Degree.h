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
		constexpr SpFloat const getValueDegrees() const {
			return this->value;
		}

		constexpr SpFloat const getValueRadians() const {
			return this->value * PI / 180.0F;
		}

	private:
		SpFloat value;
	};
}