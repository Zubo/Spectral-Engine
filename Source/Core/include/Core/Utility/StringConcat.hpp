#pragma once

#include <sstream>

#include <PlatformIndependence/SpString.hpp>

namespace sp {
	template <typename ...T>
	SpString Concat(T&&... args) {
		std::stringstream ss;
		(void)(ss << ... << std::forward<T>(args));
		return ss.str();
	}
}