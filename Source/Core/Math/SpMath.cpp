#include <cmath>

#include "Degree.h"
#include "Radian.h"
#include "SpMath.h"

namespace sp {
	SpFloat const sin(Radian const rad) {
		return std::sin(rad.getValueRadians());
	}

	SpFloat const sin(Degree const degree) {
		return std::sin(degree.getValueRadians());
	}

	SpFloat const cos(Radian const rad) {
		return std::cos(rad.getValueRadians());
	}

	SpFloat const cos(Degree const degree) {
		return std::cos(degree.getValueRadians());
	}

	SpFloat const tan(Degree const degree) {
		return std::tan(degree.getValueRadians());
	}

	SpFloat const tan(Radian const radian) {
		return std::tan(radian.getValueRadians());
	}

	SpFloat const sqrt(SpFloat const number) {
		return std::sqrt(number);
	}
}
