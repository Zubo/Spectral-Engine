#include "Game/Components/PositionOscilator.h"

#include <memory>

#include "Core/Math/SpMath.h"
#include "Core/Math/Radian.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/Transform.h"

namespace sp {
	PositionOscilator::PositionOscilator(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void PositionOscilator::update(float deltaTime) {
		timePassed += deltaTime;

		std::weak_ptr<Transform> transformWeak = this->gameObjectOwner->getComponent<Transform>();

		if (std::shared_ptr<Transform> transformShared = transformWeak.lock()) {
			sp::Radian timePassedRadian{ timePassed };
			transformShared->setPosition(5.0F * sin(timePassedRadian));
		}
	}
}
