#include <Render/RenderDataContainer.hpp>

#include <Render/RenderData.hpp>

namespace sp {
	RenderData const & RenderDataContainer::getRenderData(SpInt const gameObjectId) const {
		return _renderDataMap.at(gameObjectId);
	}

	std::unordered_map<int, RenderData> const & RenderDataContainer::getRenderDataMap() const {
		return _renderDataMap;
	}

	void RenderDataContainer::saveRenderData(RenderData const & renderData) {
		SpInt const gameObjectId = renderData.GameObjectId;
		_renderDataMap.insert_or_assign(gameObjectId, renderData);
	}

	void RenderDataContainer::resetAllChangedFlags() {
		auto renderDataIter = _renderDataMap.begin();
		auto const renderDataIterEnd = _renderDataMap.end();

		for (renderDataIter; renderDataIter != renderDataIterEnd; ++renderDataIter) {
			RenderData & renderData = renderDataIter->second;
			renderData.ModelMatrixChanged = false;
		}
	}
}
