#include "Degree.h"
#include "Radian.h"

namespace sp {
	Degree::Degree() : value{ 0.0F } {
	}

	Degree::Degree(SpFloat value) : value{ value } {
	}

	Degree::Degree(Radian radian) {
		this->value = radian.getValueRadians() * 180.0F / PI;
	}
	Degree Degree::operator/(SpFloat const value) const
	{
		return Degree{ this->getValueDegrees() / value };
	}
}