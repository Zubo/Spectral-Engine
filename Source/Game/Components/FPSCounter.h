#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "PlatformIndependence/SpType.h"

#define FPS_RENDER_PERIOD 0.35F

namespace sp {
	class FPSCounter : public GameObjectComponent {
	public:
		FPSCounter(GameObject * const gameObject);

	public:
		void update(float const deltaTime) override;

	private:
		float timeSinceLastRender;
		SpInt numberOfFrames;
	};
}
