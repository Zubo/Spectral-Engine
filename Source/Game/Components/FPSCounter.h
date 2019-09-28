#pragma once

#include "Game/Components/GameObjectComponent.h"

namespace sp {
	class FPSCounter : public GameObjectComponent {
	public:
		FPSCounter(GameObject * const gameObject);

	public:
		void update(float const deltaTime) override;
	};
}
