#include "Game/Components/FPSCounter.h"

#include <cmath>
#include <memory>
#include <sstream>

#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	FPSCounter::FPSCounter(GameObject * const gameObject) : GameObjectComponent(gameObject) {
		_timeSinceLastRender = 0.0F;
	}

	void FPSCounter::update(SpFloat const deltaTime) {
		_timeSinceLastRender += deltaTime;
		_numberOfFrames++;

		if (_timeSinceLastRender < FPS_RENDER_PERIOD) {
			return;
		}

		// Render text

		_timeSinceLastRender = 0.0F;
		_numberOfFrames = 0;
	}
}
