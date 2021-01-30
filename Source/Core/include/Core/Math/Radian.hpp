#pragma once

#include <Core/Math/SpMath.hpp>

namespace sp {
	class Degree;

	class Radian {
	public:
		Radian();
		Radian(Radian const & radian) = default;
		Radian(SpFloat const value);
		Radian(Degree const degree);

	public:
		SpFloat getValueRadians() const {
			return _value;
		}

		SpFloat getVlueDegrees() const {
			return _value * 180.0F / PI;
		}

	private:
		SpFloat _value;
	};
}
