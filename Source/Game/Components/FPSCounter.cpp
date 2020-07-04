#include "Game/Components/FPSCounter.h"

#include <cmath>
#include <memory>
#include <sstream>

#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	FPSCounter::FPSCounter(GameObject * const gameObject) : GameObjectComponent(gameObject) {
		this->_timeSinceLastRender = 0.0F;
	}

	void FPSCounter::update(SpFloat const deltaTime) {
		this->_timeSinceLastRender += deltaTime;
		this->_numberOfFrames++;

		if (this->_timeSinceLastRender < FPS_RENDER_PERIOD) {
			return;
		}

		// Render text

		this->_timeSinceLastRender = 0.0F;
		this->_numberOfFrames = 0;
	}
}
