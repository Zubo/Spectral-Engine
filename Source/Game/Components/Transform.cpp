#include "Transform.h"
#include "Core/Math/Degree.h"
#include "Core/Math/Direction.h"
#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"

namespace sp {
	Transform::Transform(GameObject * const gameObjectOwner) :
		GameObjectComponent(gameObjectOwner),
		position{ 0.0F },
		scaleVec{ 1.0F } {
	}

	Vector3 const Transform::getPosition() const {
		return this->position;
	}

	void Transform::setPosition(Vector3 const & position) {
		this->position = position;
	}

	Matrix4x4 const Transform::getTransformMatrix() const {
		Matrix4x4 transformMatrix;
		transformMatrix = scale(transformMatrix, this->scaleVec);
		transformMatrix = rotateX(transformMatrix, Degree{ this->rotationEuler.x });
		transformMatrix = rotateY(transformMatrix, Degree{ this->rotationEuler.y });
		transformMatrix = rotateZ(transformMatrix, Degree{ this->rotationEuler.z });
		transformMatrix = translate(transformMatrix, this->position);

		return transformMatrix;
	}

	Vector3 const Transform::getRotationEuler() const {
		return this->rotationEuler;
	}

	void Transform::setRotationEuler(Vector3 const & rotation) {
		this->rotationEuler = rotation;
	}

	void Transform::setScale(Vector3 const & scale) {
		this->scaleVec = scale;
	}

	Vector3 const Transform::getScale() const {
		return this->scaleVec;
	}

	Matrix4x4 const Transform::getTranslationMatrix() const {
		Matrix4x4 mat;
		return translate(mat, this->position);
	}
}
