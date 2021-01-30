#include <Scene/Components/Rotator.h>

#include <Core/Math/Radian.h>
#include <Core/Math/SpMath.h>
#include <Scene/GameObject/GameObject.h>
#include <Scene/Components/Transform.h>

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
