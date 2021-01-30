#include <Scene/Components/Rotator.hpp>

#include <Core/Math/Radian.hpp>
#include <Core/Math/SpMath.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Scene/Components/Transform.hpp>

namespace sp {
	Rotator::Rotator(GameObject * const gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Rotator::update(SpFloat deltaTime) {
		_passedTime += deltaTime;
		OptionalRef<Transform> transformOptionalRef = _gameObjectOwner->getComponent<Transform>();
		if (transformOptionalRef.HasRef()) {
			SpFloat const rotY{ sin(Radian{ _passedTime * 0.2F }) * 360.0F };
			Vector3 const rotationVector{ 0.0F, rotY, 0.0F };
			transformOptionalRef->setRotationEuler(rotationVector);
		}
	}
}
