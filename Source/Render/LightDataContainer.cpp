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
		this->lightDataMap.insert_or_assign(lightDataId, lightData);
	}

	LightData const & LightDataContainer::getLightData(int const gameObjectId) {
		return this->lightDataMap.at(gameObjectId);
	}

	std::map<int, LightData> const & LightDataContainer::getLightDataMap() const {
		return this->lightDataMap;
	}
}
