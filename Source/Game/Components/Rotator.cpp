#include "Game/Components/Rotator.h"

#include "Core/Math/Radian.h"
#include "Core/Math/SpMath.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/Transform.h"

namespace sp {
	Rotator::Rotator(GameObject * const gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void Rotator::update(SpFloat deltaTime) {
		_passedTime += deltaTime;
		auto transformComponentWeak = _gameObjectOwner->getComponent<Transform>();
		if (auto transformComponentShared = transformComponentWeak.lock()) {
			SpFloat const rotY{ sin(Radian{ _passedTime * 0.2F }) * 360.0F };
			Vector3 const rotationVector{ 0.0F, rotY, 0.0F };
			transformComponentShared->setRotationEuler(rotationVector);
		}
	}
}
