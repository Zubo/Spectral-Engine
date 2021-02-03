#include <Render/GUI/GUIDrawCallDataContainer.hpp>

namespace sp {
	std::queue<GUIDrawCallData> & GUIDrawCallDataContainer::getDrawCallDataQueue() {
		return _drawCallDataQueue;
	}

	void GUIDrawCallDataContainer::enqueueDrawCallData(GUIDrawCallData const & guiDrawCallData) {
		_drawCallDataQueue.push(guiDrawCallData);
	}
}
