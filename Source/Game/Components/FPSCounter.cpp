#include "Game/Components/FPSCounter.h"

#include <cmath>
#include <memory>
#include <sstream>

#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	FPSCounter::FPSCounter(GameObject * const gameObject) : GameObjectComponent(gameObject) {
		this->timeSinceLastRender = 0.0F;
	}

	void FPSCounter::update(SpFloat const deltaTime) {
		this->timeSinceLastRender += deltaTime;
		this->numberOfFrames++;

		if (this->timeSinceLastRender < FPS_RENDER_PERIOD) {
			return;
		}

		// Render text

		this->timeSinceLastRender = 0.0F;
		this->numberOfFrames = 0.0F;
	}
}
