#include <Render/RenderData.hpp>

#include <Core/Math/Degree.hpp>
#include <Core/Math/LinearTransformations.hpp>

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
