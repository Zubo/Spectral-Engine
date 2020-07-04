#include "Degree.h"
#include "Radian.h"

namespace sp {
	Radian::Radian() : _value{ 0.0F } {
	}

	Radian::Radian(SpFloat const value) : _value{ value } {
	}

	Radian::Radian(Degree const degree) {
		this->_value = degree.getValueRadians();
	}
}
