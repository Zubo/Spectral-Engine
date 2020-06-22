#pragma once

#include <map>

#include "PlatformIndependence/SpType.h"

namespace sp {
	class RenderData;

	class RenderDataContainer {
	public:
		RenderData const & getRenderData(SpInt const gameObjectId) const;
		std::map<int, RenderData> const & getRenderDataMap() const;
		void saveRenderData(RenderData const & renderData);
		void resetAllChangedFlags();
		static RenderDataContainer & getInstance();

	private:
		RenderDataContainer() = default;
		RenderDataContainer(RenderDataContainer const & renderDataContainer) = delete;
		RenderDataContainer operator=(RenderDataContainer & renderDataCOntainer) = delete;

	private:
		std::map<int, RenderData> renderDataMap;
		static RenderDataContainer instance;
	};
}
