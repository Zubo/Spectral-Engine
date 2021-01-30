#pragma once

#include "PlatformIndependence/SpString.h"

namespace sp {
	class FileReader {
	public:
		static SpString const ReadFromFile(SpString const path);
	};
}
