#include <memory>

#include "Core/Math/SpMath.h"
#include "Core/Math/Radian.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/PositionOscilator.h"
#include "Game/Components/Transform.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	PositionOscilator::PositionOscilator(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void PositionOscilator::update(SpFloat deltaTime) {
		_timePassed += deltaTime;

		std::weak_ptr<Transform> transformWeak = _gameObjectOwner->getComponent<Transform>();

		if (std::shared_ptr<Transform> transformShared = transformWeak.lock()) {
			sp::Radian timePassedRadian{ _timePassed };
			transformShared->setPosition(5.0F * sin(timePassedRadian));
		}
	}
}
