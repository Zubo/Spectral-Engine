#include "Render/RenderData.h"

namespace sp {
	RenderData::RenderData(
		int const gameObjectId, bool const active, bool const isStatic)
		: gameObjectId{ gameObjectId }, active{ active }, isStatic{ isStatic } {
	}

	RenderData const & RenderData::operator=(RenderData const & renderData) {
		return RenderData{ renderData };
	}
}
