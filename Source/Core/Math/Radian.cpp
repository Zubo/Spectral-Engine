#include "Degree.h"
#include "Radian.h"

namespace sp {
	Radian::Radian() : value{ 0.0F } {
	}

	Radian::Radian(SpFloat const value) : value{ value } {
	}

	Radian::Radian(Degree const degree) {
		this->value = degree.getValueRadians();
	}
}
