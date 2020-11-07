#include <memory>

#include "Core/Math/SpMath.h"
#include "Core/Math/Radian.h"
#include "Scene/GameObject/GameObject.h"
#include "Scene/Components/PositionOscilator.h"
#include "Scene/Components/Transform.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	PositionOscilator::PositionOscilator(GameObject * gameObjectOwner) : GameObjectComponent{ gameObjectOwner } {
	}

	void PositionOscilator::update(SpFloat deltaTime) {
		_timePassed += deltaTime;

		OptionalRef<Transform> transformRef = _gameObjectOwner->getComponent<Transform>();

		if (transformRef.HasRef()) {
			sp::Radian timePassedRadian{ _timePassed };
			transformRef->setPosition(5.0F * sin(timePassedRadian));
		}
	}
}
