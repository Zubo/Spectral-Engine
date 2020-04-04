#pragma once

#include <map>

namespace sp {
	class RenderData;

	class RenderDataContainer {
	public:
		RenderData const & getRenderData(int const gameObjectId) const;
		std::map<int, RenderData> const & getRenderDataMap() const;
		void saveRenderData(RenderData const & renderData);
		void resetAllModelMatrixUpdated();
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
