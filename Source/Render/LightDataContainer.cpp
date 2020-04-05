#include "Render/LightDataContainer.h"

#include <map>

#include "Render/LightData.h"

namespace sp {
	LightDataContainer LightDataContainer::instance;

	LightDataContainer & LightDataContainer::getInstance() {
		return LightDataContainer::instance;
	}

	LightDataContainer::LightDataContainer() {
	}

	void LightDataContainer::saveLightData(LightData const & lightData) {
		int const lightDataId = lightData.id;
		
		int const previousLightCount = this->lightDataMap.size();

		this->lightDataMap.insert_or_assign(lightDataId, lightData);

		this->numberOfLightsChanged = 
			this->numberOfLightsChanged ||
			(this->lightDataMap.size() != previousLightCount);
	}

	LightData const & LightDataContainer::getLightData(int const lightDataId) {
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
			sp::LightData & lightData = lightDataIter->second;
			lightData.changed = false;
		}
	}
}
