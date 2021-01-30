#include "Degree.h"
#include "Radian.h"

namespace sp {
	Degree::Degree() : _value{ 0.0F } {
	}

	Degree::Degree(SpFloat value) : _value{ value } {
	}

	Degree::Degree(Radian radian) {
		_value = radian.getValueRadians() * 180.0F / PI;
	}

	Degree Degree::operator/(SpFloat const degreeValue) const
	{
		return Degree{ getValueDegrees() / degreeValue };
	}
}
