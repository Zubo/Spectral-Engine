#include "Render/RenderData.h"

#include "Core/Math/Degree.h"
#include "Core/Math/LinearTransformations.h"

namespace sp {
	RenderData::RenderData(
		int const gameObjectId, bool const active, bool const isStatic)
		: gameObjectId{ gameObjectId }, active{ active }, isStatic{ isStatic }, scale{ 1.0F } {
	}

	Matrix4x4 const RenderData::GetModelMatrix() const {
		Matrix4x4 modelMatrix;

		modelMatrix = rotateX(modelMatrix, Degree{ this->rotationEuler.x });
		modelMatrix = rotateY(modelMatrix, Degree{ this->rotationEuler.y });
		modelMatrix = rotateZ(modelMatrix, Degree{ this->rotationEuler.z });
		modelMatrix = translate(modelMatrix, this->position);
		modelMatrix = sp::scale(modelMatrix, this->scale);

		return modelMatrix;
	}
}
