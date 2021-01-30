#pragma once

#include <PlatformIndependence/SpString.hpp>

namespace sp {
	class FileReader {
	public:
		static SpString const ReadFromFile(SpString const path);
	};
}
