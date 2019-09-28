#include "Game/Components/FPSCounter.h"

#include <cmath>
#include <memory>
#include <sstream>

#include "Game/Components/UI/TextRenderer.h"
#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	FPSCounter::FPSCounter(GameObject * const gameObject) : GameObjectComponent(gameObject) {
	}

	void FPSCounter::update(float const deltaTime) {
		std::weak_ptr<TextRenderer> textRendererWeak = this->gameObjectOwner->getComponent<TextRenderer>();

		if (auto textRendererShared = textRendererWeak.lock()) {
			float const fps = std::ceil(1.0F / deltaTime * 10.0F) / 10.0F;

			std::ostringstream ss;
			ss << fps;
			SpString fpsString{ ss.str() };
			textRendererShared->setText(fpsString);
		}
	}
}
