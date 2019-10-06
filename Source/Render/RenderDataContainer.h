#include <map>

namespace sp {
	class RenderData;

	class RenderDataContainer {
	public:
		RenderData const getRenderData(int const gameObjectId) const;;
		std::map<int, RenderData>::const_iterator getRenderDataIterator() const;
		void updateRenderData(int const gameObjectId, RenderData const & renderData);

	private:
		std::map<int, RenderData> renderDataMap;
	};
}
