#pragma once

#include "Core/Math/SpMath.h"

namespace sp {
	class Degree;

	class Radian {
	public:
		Radian();
		Radian(Radian const & radian) = default;
		Radian(SpFloat const value);
		Radian(Degree const degree);

	public:
		constexpr SpFloat const getValueRadians() const {
			return this->_value;
		}

		constexpr SpFloat const getVlueDegrees() const {
			return this->_value * 180.0F / PI;
		}

	private:
		SpFloat _value;
	};
}
