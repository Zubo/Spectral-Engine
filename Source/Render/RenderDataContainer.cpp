#include "RenderDataContainer.h"

#include "Render/RenderData.h"

namespace sp {
	RenderData const RenderDataContainer::getRenderData(int const gameObjectId) const {
		return this->renderDataMap.at(gameObjectId);
	}

	std::map<int, RenderData>::const_iterator RenderDataContainer::getRenderDataIterator() const {
		return this->renderDataMap.begin();
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
}
