#pragma once

#include <unordered_map>

#include <PlatformIndependence/SpType.hpp>
#include <Render/Enum/LightType.hpp>
#include <Render/LightData.hpp>

namespace sp {
	class Vector3;

	class LightDataContainer {
	public:
		LightDataContainer();

	public:
		void saveLightData(LightData const & lightData);
		LightData const & getLightData(SpInt const gameObjectId);
		std::unordered_map<int, LightData> const & getLightDataMap() const;
		bool getNumberOfLightsChanged() const;
		void setNumberOfLightsChangedToFalse();
		void setAllLightDataChangedToFalse();

	private:
		LightDataContainer(LightDataContainer const & lightDataContainer) = delete;
		LightDataContainer & operator=(LightDataContainer & lightDataContainer) = delete;

	private:
		std::unordered_map<int, LightData> _lightDataMap;
		bool _numberOfLightsChanged = false;
	};
}
