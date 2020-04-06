#include "Game/Components/FPSCounter.h"

#include <cmath>
#include <memory>
#include <sstream>

#include "Game/Components/UI/TextRenderer.h"
#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	FPSCounter::FPSCounter(GameObject * const gameObject) : GameObjectComponent(gameObject) {
		this->timeSinceLastRender = 0.0F;
	}

	void FPSCounter::update(float const deltaTime) {
		this->timeSinceLastRender += deltaTime;
		this->numberOfFrames++;

		if (this->timeSinceLastRender < FPS_RENDER_PERIOD) {
			return;
		}

		std::weak_ptr<TextRenderer> textRendererWeak = this->gameObjectOwner->getComponent<TextRenderer>();

		if (auto textRendererShared = textRendererWeak.lock()) {
			float const averageFramePeriod = this->timeSinceLastRender / this->numberOfFrames;
			float const fps = std::ceil(1.0F / averageFramePeriod * 10.0F) / 10.0F;

			std::ostringstream ss;
			ss << fps;

			SpString fpsString{ ss.str() };

			textRendererShared->setText(fpsString);
		}

		this->timeSinceLastRender = 0.0F;
		this->numberOfFrames = 0.0F;
	}
}
