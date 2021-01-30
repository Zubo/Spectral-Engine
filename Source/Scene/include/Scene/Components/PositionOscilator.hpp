#pragma once

#include <Scene/Components/GameObjectComponent.hpp>

namespace sp {
	class PositionOscilator : public GameObjectComponent {
	public:
		PositionOscilator(GameObject * gameObjectOwner);

	public:
		void update(SpFloat deltaTime) override;

	private:
		SpFloat _timePassed = 0.0F;
	};
}
