#pragma once

#include "Game/Components/GameObjectComponent.h"

namespace sp {
	class PositionOscilator : public GameObjectComponent {
	public:
		PositionOscilator(GameObject * gameObjectOwner);

	public:
		void update(SpFloat deltaTime) override;

	private:
		SpFloat timePassed = 0.0F;
	};
}
