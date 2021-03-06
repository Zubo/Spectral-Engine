#include <cmath>

#include <Core/Math/Degree.hpp>
#include <Core/Math/Radian.hpp>
#include <Core/Math/SpMath.hpp>

namespace sp {
	SpFloat sin(Radian const rad) {
		return std::sin(rad.getValueRadians());
	}

	SpFloat sin(Degree const degree) {
		return std::sin(degree.getValueRadians());
	}

	SpFloat cos(Radian const rad) {
		return std::cos(rad.getValueRadians());
	}

	SpFloat cos(Degree const degree) {
		return std::cos(degree.getValueRadians());
	}

	SpFloat tan(Degree const degree) {
		return std::tan(degree.getValueRadians());
	}

	SpFloat tan(Radian const radian) {
		return std::tan(radian.getValueRadians());
	}

	SpFloat sqrt(SpFloat const number) {
		return std::sqrt(number);
	}
}
