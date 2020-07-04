#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "PlatformIndependence/SpType.h"

#define FPS_RENDER_PERIOD 0.35F

namespace sp {
	class FPSCounter : public GameObjectComponent {
	public:
		FPSCounter(GameObject * const gameObject);

	public:
		void update(SpFloat const deltaTime) override;

	private:
		SpFloat _timeSinceLastRender;
		SpInt _numberOfFrames;
	};
}
