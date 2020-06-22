#pragma once

#include <map>

#include "PlatformIndependence/SpType.h"
#include "Render/Enum/LightType.h"
#include "Render/LightData.h"

namespace sp {
	class Vector3;

	class LightDataContainer {
	public:
		static LightDataContainer & getInstance();
		void saveLightData(LightData const & lightData);
		LightData const & getLightData(SpInt const gameObjectId);
		std::map<int, LightData> const & getLightDataMap() const;
		bool const getNumberOfLightsChanged() const;
		void setNumberOfLightsChangedToFalse();
		void setAllLightDataChangedToFalse();

	private:
		LightDataContainer();
		LightDataContainer(LightDataContainer const & lightDataContainer) = delete;
		LightDataContainer & operator=(LightDataContainer & lightDataContainer) = delete;

	private:
		static LightDataContainer instance;
		std::map<int, LightData> lightDataMap;
		bool numberOfLightsChanged = false;
	};
}
