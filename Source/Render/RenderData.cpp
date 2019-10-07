#include "Render/RenderData.h"

namespace sp {
	RenderData::RenderData(
		int const gameObjectId, ShaderProgram const shaderProgram, bool const active, bool isStatic)
		: gameObjectId{ gameObjectId }, shaderProgram{ shaderProgram }, active{ active }, isStatic{ isStatic } {
	}

	RenderData const & RenderData::operator=(RenderData const & renderData) {
		return RenderData{ renderData };
	}
}
