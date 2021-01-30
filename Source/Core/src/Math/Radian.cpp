#include <Core/Math/Degree.hpp>
#include <Core/Math/Radian.hpp>

namespace sp {
	Radian::Radian() : _value{ 0.0F } {
	}

	Radian::Radian(SpFloat const value) : _value{ value } {
	}

	Radian::Radian(Degree const degree) {
		_value = degree.getValueRadians();
	}
}
