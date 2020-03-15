#include "RenderDataContainer.h"

#include "Render/RenderData.h"

namespace sp {
	RenderDataContainer RenderDataContainer::instance;

	RenderData const & RenderDataContainer::getRenderData(int const gameObjectId) const {
		return this->renderDataMap.at(gameObjectId);
	}

	std::map<int, RenderData> const & RenderDataContainer::getRenderDataMap() const {
		return this->renderDataMap;
	}

	void RenderDataContainer::updateRenderData(RenderData const & renderData) {
		int const gameObjectId = renderData.gameObjectId;
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

	void RenderDataContainer::resetAllModelMatrixUpdated() {
		auto renderDataIter = this->renderDataMap.begin();
		auto const renderDataIterEnd = this->renderDataMap.end();

		for (renderDataIter; renderDataIter != renderDataIterEnd; ++renderDataIter) {
			sp::RenderData & renderData = renderDataIter->second;
			renderData.modelMatrixChanged = false;
		}
	}

	RenderDataContainer & RenderDataContainer::GetInstance() {
		return RenderDataContainer::instance;
	}
}
