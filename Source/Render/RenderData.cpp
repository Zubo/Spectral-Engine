#include "Render/RenderData.h"

namespace sp {
	RenderData::RenderData(
		int const gameObjectId, bool const active, bool const isStatic)
		: gameObjectId{ gameObjectId }, active{ active }, isStatic{ isStatic } {
	}

	Matrix4x4 const RenderData::GetModelMatrix() const {
		return 
			this->roatationMatrix *
			this->scaleMatrix *
			this->translationMatrix;
	}

	RenderData const & RenderData::operator=(RenderData const & renderData) {
		return RenderData{ renderData };
	}
}
