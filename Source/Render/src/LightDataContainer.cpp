#include <Render/LightDataContainer.hpp>

#include <unordered_map>

#include <PlatformIndependence/SpType.hpp>
#include <Render/LightData.hpp>

namespace sp {
	LightDataContainer::LightDataContainer() {
	}

	void LightDataContainer::saveLightData(LightData const & lightData) {
		SpInt const lightDataId = lightData.Id;

		std::size_t const previousLightCount = _lightDataMap.size();

		_lightDataMap.insert_or_assign(lightDataId, lightData);

		_numberOfLightsChanged =
			_numberOfLightsChanged ||
			(_lightDataMap.size() != previousLightCount);
	}

	LightData const & LightDataContainer::getLightData(SpInt const lightDataId) {
		return _lightDataMap.at(lightDataId);
	}

	std::unordered_map<int, LightData> const & LightDataContainer::getLightDataMap() const {
		return _lightDataMap;
	}

	bool LightDataContainer::getNumberOfLightsChanged() const {
		return _numberOfLightsChanged;
	}

	void LightDataContainer::setNumberOfLightsChangedToFalse() {
		_numberOfLightsChanged = false;
	}

	void LightDataContainer::setAllLightDataChangedToFalse() {
		auto lightDataIter = _lightDataMap.begin();
		auto lightDataIterEnd = _lightDataMap.end();

		for (; lightDataIter != lightDataIterEnd; ++lightDataIter) {
			LightData & lightData = lightDataIter->second;
			lightData.Changed = false;
		}
	}
}
