#pragma once

#include <map>

#include "Render/Enum/LightType.h"
#include "Render/LightData.h"

namespace sp {
	class Vector3;

	class LightDataContainer {
	public:
		static LightDataContainer const & getInstance();
		void saveLightData(LightData const & lightData);
		std::map<int, LightData> const & getLightDataMap() const;

	private:
		LightDataContainer() = delete;
		LightDataContainer(LightDataContainer const & lightDataContainer) = delete;
		LightDataContainer & operator=(LightDataContainer & lightDataContainer) = delete;

	private:
		static LightDataContainer instance;
		std::map<int, LightData> lightDataMap;
	};
}
