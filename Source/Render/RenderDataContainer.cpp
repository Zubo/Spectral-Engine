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

	void RenderDataContainer::saveRenderData(RenderData const & renderData) {
		int const gameObjectId = renderData.gameObjectId;
		this->renderDataMap.insert_or_assign(gameObjectId, renderData);
	}

	void RenderDataContainer::resetAllModelMatrixUpdated() {
		auto renderDataIter = this->renderDataMap.begin();
		auto const renderDataIterEnd = this->renderDataMap.end();

		for (renderDataIter; renderDataIter != renderDataIterEnd; ++renderDataIter) {
			sp::RenderData & renderData = renderDataIter->second;
			renderData.modelMatrixChanged = false;
		}
	}

	RenderDataContainer & RenderDataContainer::getInstance() {
		return RenderDataContainer::instance;
	}
}
