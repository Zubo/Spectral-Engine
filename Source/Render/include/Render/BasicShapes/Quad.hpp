#pragma once

#include <PlatformIndependence/SpType.hpp>

namespace sp {
	constexpr SpFloat quad[] = {
		1.0F, 1.0F, 0.0F,
		0.0F, 1.0F, 0.0F,
		0.0F, 0.0F, 0.0F,
		1.0F, 1.0F, 0.0F,
		0.0F, 0.0F, 0.0F,
		1.0F, 0.0F, 0.0F
	};

	constexpr SpFloat quadUV[] = {
		1.0F, 1.0F, 0.0F, 1.0F, 1.0F,
		0.0F, 1.0F, 0.0F, 0.0F, 1.0F,
		0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
		1.0F, 1.0F, 0.0F, 1.0F, 1.0F,
		0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
		1.0F, 0.0F, 0.0F, 1.0F, 0.0F
	};
}
