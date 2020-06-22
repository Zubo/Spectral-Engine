#include "Render/LightDataContainer.h"

#include <map>

#include "PlatformIndependence/SpType.h"
#include "Render/LightData.h"

namespace sp {
	LightDataContainer LightDataContainer::instance;

	LightDataContainer & LightDataContainer::getInstance() {
		return LightDataContainer::instance;
	}

	LightDataContainer::LightDataContainer() {
	}

	void LightDataContainer::saveLightData(LightData const & lightData) {
		SpInt const lightDataId = lightData.id;
		
		SpInt const previousLightCount = this->lightDataMap.size();

		this->lightDataMap.insert_or_assign(lightDataId, lightData);

		this->numberOfLightsChanged = 
			this->numberOfLightsChanged ||
			(this->lightDataMap.size() != previousLightCount);
	}

	LightData const & LightDataContainer::getLightData(SpInt const lightDataId) {
		return this->lightDataMap.at(lightDataId);
	}

	std::map<int, LightData> const & LightDataContainer::getLightDataMap() const {
		return this->lightDataMap;
	}

	bool const LightDataContainer::getNumberOfLightsChanged() const {
		return this->numberOfLightsChanged;
	}

	void LightDataContainer::setNumberOfLightsChangedToFalse() {
		this->numberOfLightsChanged = false;
	}

	void LightDataContainer::setAllLightDataChangedToFalse() {
		auto lightDataIter = this->lightDataMap.begin();
		auto lightDataIterEnd = this->lightDataMap.end();

		for (lightDataIter; lightDataIter != lightDataIterEnd; ++lightDataIter) {
			LightData & lightData = lightDataIter->second;
			lightData.changed = false;
		}
	}
}
