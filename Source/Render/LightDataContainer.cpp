#include "Render/LightDataContainer.h"

#include <map>

#include "Render/LightData.h"

namespace sp {
	LightDataContainer const & LightDataContainer::getInstance() {
		return LightDataContainer::instance;
	}

	void LightDataContainer::saveLightData(LightData const & lightData) {
		int const lightDataId = lightData.id;
		this->lightDataMap.insert_or_assign(lightDataId, lightData);
	}

	std::map<int, LightData> const & LightDataContainer::getLightDataMap() const {
		return this->lightDataMap;
	}
}
