#pragma once

#include "PlatformIndependence/SpType.h"

namespace sp {
	class Radian;
	class Degree;

	#define PI 3.14159265358979323846F

	SpFloat const sin(Radian const rad);
	SpFloat const sin(Degree const degree);
	SpFloat const cos(Radian const rad);
	SpFloat const cos(Degree const degree);
	SpFloat const tan(Radian const radian);
	SpFloat const tan(Degree const degree);
	SpFloat const sqrt(SpFloat const number);
}