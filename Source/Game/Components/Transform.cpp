#include "Game/Components/Transform.h"

#include <memory>

#include "Core/Math/Degree.h"
#include "Core/Math/Direction.h"
#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"
#include "Game/Components/Renderer.h"
#include "Game/GameObject/GameObject.h"
#include "Render/RenderDataUpdate.h"

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

		if (this->hasMesh()) {
			int const gameObjectId = this->gameObjectOwner->getId();
			updateTranslation(gameObjectId, this->position);
		}
	}

	Vector3 const Transform::getRotationEuler() const {
		return this->rotationEuler;
	}

	void Transform::setRotationEuler(Vector3 const & rotation) {
		this->rotationEuler = rotation;

		if (this->hasMesh()) {
			int const gameObjectId = this->gameObjectOwner->getId();
			updateRotation(gameObjectId, this->rotationEuler);
		}
	}

	void Transform::setScale(Vector3 const & scale) {
		this->scaleVec = scale;

		if (this->hasMesh()) {
			int const gameObjectId = this->gameObjectOwner->getId();
			updateScale(gameObjectId, this->scaleVec);
		}
	}

	Vector3 const Transform::getScale() const {
		return this->scaleVec;
	}

	bool const Transform::hasMesh() const {
		std::weak_ptr<Renderer> rendererWeak = this->gameObjectOwner->getComponent<Renderer>();
		return (bool)rendererWeak.lock();
	}
}
