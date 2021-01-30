#include <memory>

#include <Core/Math/SpMath.hpp>
#include <Core/Math/Radian.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Scene/Components/PositionOscilator.hpp>
#include <Scene/Components/Transform.hpp>
#include <PlatformIndependence/SpType.hpp>

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
