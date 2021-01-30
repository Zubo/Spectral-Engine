#pragma once

#include <unordered_map>

#include <PlatformIndependence/SpType.hpp>
#include <Render/RenderData.hpp>

namespace sp {
	class RenderDataContainer {
	public:
		RenderDataContainer() = default;

	private:
		RenderDataContainer(RenderDataContainer const & renderDataContainer) = delete;
		RenderDataContainer operator=(RenderDataContainer & renderDataCOntainer) = delete;

	public:
		RenderData const & getRenderData(SpInt const gameObjectId) const;
		std::unordered_map<int, RenderData> const & getRenderDataMap() const;
		void saveRenderData(RenderData const & renderData);
		void resetAllChangedFlags();

	private:
		std::unordered_map<int, RenderData> _renderDataMap;
	};
}
