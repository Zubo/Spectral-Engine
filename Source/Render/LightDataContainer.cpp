#include "Render/LightDataContainer.h"

#include <map>

#include "PlatformIndependence/SpType.h"
#include "Render/LightData.h"

namespace sp {
	LightDataContainer LightDataContainer::_instance;

	LightDataContainer & LightDataContainer::getInstance() {
		return LightDataContainer::_instance;
	}

	LightDataContainer::LightDataContainer() {
	}

	void LightDataContainer::saveLightData(LightData const & lightData) {
		SpInt const lightDataId = lightData.Id;

		SpInt const previousLightCount = this->_lightDataMap.size();

		this->_lightDataMap.insert_or_assign(lightDataId, lightData);

		this->_numberOfLightsChanged =
			this->_numberOfLightsChanged ||
			(this->_lightDataMap.size() != previousLightCount);
	}

	LightData const & LightDataContainer::getLightData(SpInt const lightDataId) {
		return this->_lightDataMap.at(lightDataId);
	}

	std::map<int, LightData> const & LightDataContainer::getLightDataMap() const {
		return this->_lightDataMap;
	}

	bool const LightDataContainer::getNumberOfLightsChanged() const {
		return this->_numberOfLightsChanged;
	}

	void LightDataContainer::setNumberOfLightsChangedToFalse() {
		this->_numberOfLightsChanged = false;
	}

	void LightDataContainer::setAllLightDataChangedToFalse() {
		auto lightDataIter = this->_lightDataMap.begin();
		auto lightDataIterEnd = this->_lightDataMap.end();

		for (lightDataIter; lightDataIter != lightDataIterEnd; ++lightDataIter) {
			LightData & lightData = lightDataIter->second;
			lightData.Changed = false;
		}
	}
}
