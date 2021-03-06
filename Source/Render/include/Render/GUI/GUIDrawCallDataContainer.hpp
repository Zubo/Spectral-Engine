#pragma once

#include <queue>

#include <Render/GUI/DrawCallData/GUIDrawCallData.hpp>

namespace sp {
	class GUIDrawCallDataContainer {
	public:
		std::queue<GUIDrawCallData> & getDrawCallDataQueue();
		void enqueueDrawCallData(GUIDrawCallData const & guiDrawCallData);

	private:
		std::queue<GUIDrawCallData> _drawCallDataQueue;
	};
}
