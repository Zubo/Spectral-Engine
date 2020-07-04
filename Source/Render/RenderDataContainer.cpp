#include "RenderDataContainer.h"

#include "Render/RenderData.h"

namespace sp {
	RenderDataContainer RenderDataContainer::_instance;

	RenderData const & RenderDataContainer::getRenderData(SpInt const gameObjectId) const {
		return this->_renderDataMap.at(gameObjectId);
	}

	std::map<int, RenderData> const & RenderDataContainer::getRenderDataMap() const {
		return this->_renderDataMap;
	}

	void RenderDataContainer::saveRenderData(RenderData const & renderData) {
		SpInt const gameObjectId = renderData.GameObjectId;
		this->_renderDataMap.insert_or_assign(gameObjectId, renderData);
	}

	void RenderDataContainer::resetAllChangedFlags() {
		auto renderDataIter = this->_renderDataMap.begin();
		auto const renderDataIterEnd = this->_renderDataMap.end();

		for (renderDataIter; renderDataIter != renderDataIterEnd; ++renderDataIter) {
			RenderData & renderData = renderDataIter->second;
			renderData.ModelMatrixChanged = false;
		}
	}

	RenderDataContainer & RenderDataContainer::getInstance() {
		return RenderDataContainer::_instance;
	}
}
