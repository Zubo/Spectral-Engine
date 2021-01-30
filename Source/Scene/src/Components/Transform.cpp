#include <Scene/Components/Transform.hpp>

#include <memory>
#include <vector>

#include <Core/Math/Degree.hpp>
#include <Core/Math/Direction.hpp>
#include <Core/Math/LinearTransformations.hpp>
#include <Core/Math/Matrix4x4.hpp>
#include <Scene/Components/Interface/ITransformChangeObserver.hpp>
#include <Scene/Components/Renderer.hpp>
#include <Scene/GameObject/GameObject.hpp>


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

		std::vector<OptionalRef<ITransformChangeObserver>> observers =
			_gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerOptionalRef : observers) {
			if (observerOptionalRef.HasRef()) {
				observerOptionalRef->onPositionUpdated(position);
			}
		}
	}

	Vector3 const Transform::getRotationEuler() const {
		return _rotationEuler;
	}

	void Transform::setRotationEuler(Vector3 const & rotation) {
		_rotationEuler = rotation;

		std::vector<OptionalRef<ITransformChangeObserver>> observers =
			_gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerOptionalRef : observers) {
			if (observerOptionalRef.HasRef()) {
				observerOptionalRef->onRotationUpdated(rotation);
			}
		}
	}

	void Transform::setScale(Vector3 const & scale) {
		_scaleVec = scale;

		std::vector<OptionalRef<ITransformChangeObserver>> observers =
			_gameObjectOwner->getComponents<ITransformChangeObserver>();
		for (auto observerOptionalRef : observers) {
			if (observerOptionalRef.HasRef()) {
				observerOptionalRef->onScaleUpdated(scale);
			}
		}
	}

	Vector3 const Transform::getScale() const {
		return _scaleVec;
	}
}
