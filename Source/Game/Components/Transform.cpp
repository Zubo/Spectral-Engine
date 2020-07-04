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
		_position{ 0.0F },
		_scaleVec{ 1.0F } {
	}

	Vector3 const Transform::getPosition() const {
		return _position;
	}

	void Transform::setPosition(Vector3 const & position) {
		_position = position;

		std::vector<std::weak_ptr<ITransformChangeObserver>> observers =
			_gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerWeak : observers) {
			if (std::shared_ptr<ITransformChangeObserver> transformShared = observerWeak.lock()) {
				transformShared->onPositionUpdated(position);
			}
		}
	}

	Vector3 const Transform::getRotationEuler() const {
		return _rotationEuler;
	}

	void Transform::setRotationEuler(Vector3 const & rotation) {
		_rotationEuler = rotation;

		std::vector<std::weak_ptr<ITransformChangeObserver>> observers =
			_gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerWeak : observers) {
			if (std::shared_ptr<ITransformChangeObserver> transformShared = observerWeak.lock()) {
				transformShared->onRotationUpdated(rotation);
			}
		}
	}

	void Transform::setScale(Vector3 const & scale) {
		_scaleVec = scale;

		std::vector<std::weak_ptr<ITransformChangeObserver>> observers =
			_gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerWeak : observers) {
			if (std::shared_ptr<ITransformChangeObserver> transformShared = observerWeak.lock()) {
				transformShared->onScaleUpdated(scale);
			}
		}
	}

	Vector3 const Transform::getScale() const {
		return _scaleVec;
	}
}
