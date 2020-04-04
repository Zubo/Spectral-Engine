#include "Game/Components/Transform.h"

#include <memory>
#include <vector>

#include "Core/Math/Degree.h"
#include "Core/Math/Direction.h"
#include "Core/Math/LinearTransformations.h"
#include "Core/Math/Matrix4x4.h"
#include "Game/Components/Interface/ITransformChangeObserver.h"
#include "Game/Components/Renderer.h"
#include "Game/GameObject/GameObject.h"


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

		std::vector<std::weak_ptr<ITransformChangeObserver>> observers =
			this->gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerWeak : observers) {
			if (std::shared_ptr<ITransformChangeObserver> transformShared = observerWeak.lock()) {
				transformShared->onPositionUpdated(position);
			}
		}
	}

	Vector3 const Transform::getRotationEuler() const {
		return this->rotationEuler;
	}

	void Transform::setRotationEuler(Vector3 const & rotation) {
		this->rotationEuler = rotation;

		std::vector<std::weak_ptr<ITransformChangeObserver>> observers =
			this->gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerWeak : observers) {
			if (std::shared_ptr<ITransformChangeObserver> transformShared = observerWeak.lock()) {
				transformShared->onRotationUpdated(rotation);
			}
		}
	}

	void Transform::setScale(Vector3 const & scale) {
		this->scaleVec = scale;

		std::vector<std::weak_ptr<ITransformChangeObserver>> observers =
			this->gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerWeak : observers) {
			if (std::shared_ptr<ITransformChangeObserver> transformShared = observerWeak.lock()) {
				transformShared->onScaleUpdated(scale);
			}
		}
	}

	Vector3 const Transform::getScale() const {
		return this->scaleVec;
	}
}
