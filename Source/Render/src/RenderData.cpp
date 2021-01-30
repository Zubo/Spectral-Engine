#include "Render/RenderData.h"

#include "Core/Math/Degree.h"
#include "Core/Math/LinearTransformations.h"

namespace sp {
	RenderData::RenderData(
		SpInt const gameObjectId, bool const active, bool const isStatic)
		: GameObjectId{ gameObjectId }, Active{ active }, IsStatic{ isStatic }, Scale{ 1.0F } {
	}

	Matrix4x4 const RenderData::getModelMatrix() const {
		Matrix4x4 modelMatrix;

		modelMatrix = rotateX(modelMatrix, Degree{ RotationEuler.X });
		modelMatrix = rotateY(modelMatrix, Degree{ RotationEuler.Y });
		modelMatrix = rotateZ(modelMatrix, Degree{ RotationEuler.Z });
		modelMatrix = translate(modelMatrix, Position);
		modelMatrix = sp::scale(modelMatrix, Scale);

		return modelMatrix;
	}
}
