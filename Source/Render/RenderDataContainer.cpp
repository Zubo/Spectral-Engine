#include "RenderDataContainer.h"

#include "Render/RenderData.h"

namespace sp {
	RenderDataContainer RenderDataContainer::instance;

	RenderData const RenderDataContainer::getRenderData(int const gameObjectId) const {
		return this->renderDataMap.at(gameObjectId);
	}

	std::map<int, RenderData> const & RenderDataContainer::getRenderDataMap() const {
		return this->renderDataMap;
	}

	void RenderDataContainer::updateRenderData(int const gameObjectId, RenderData const & renderData) {
		auto const gameObjectIter{ this->renderDataMap.find(gameObjectId) };
		bool const renderDataExists{ (gameObjectIter != this->renderDataMap.end()) };

		if (renderDataExists) {
			gameObjectIter->second = renderData;
		}
		else {
			std::pair<int, RenderData> pair{ gameObjectId, renderData };
			this->renderDataMap.insert(pair);
		}
	}
	RenderDataContainer & RenderDataContainer::GetInstance() {
		return RenderDataContainer::instance;
	}
}
