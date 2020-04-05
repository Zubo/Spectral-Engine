#pragma once

#include "Game/Components/GameObjectComponent.h"

namespace sp {
	class PositionOscilator : public GameObjectComponent {
	public:
		PositionOscilator(GameObject * gameObjectOwner);

	public:
		void update(float deltaTime) override;

	private:
		float timePassed = 0.0F;
	};
}
