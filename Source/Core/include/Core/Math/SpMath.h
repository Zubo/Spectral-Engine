#pragma once

#include <limits>

#include <PlatformIndependence/SpType.h>

namespace sp {
	class Radian;
	class Degree;

	constexpr SpFloat PI = 3.14159265358979323846F;
	constexpr SpFloat EPSILON = std::numeric_limits<float>::epsilon();

	SpFloat sin(Radian const rad);
	SpFloat sin(Degree const degree);
	SpFloat cos(Radian const rad);
	SpFloat cos(Degree const degree);
	SpFloat tan(Radian const radian);
	SpFloat tan(Degree const degree);
	SpFloat sqrt(SpFloat const number);
}