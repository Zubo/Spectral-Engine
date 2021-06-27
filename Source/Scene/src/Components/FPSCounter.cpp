#include <Scene/Components/FPSCounter.hpp>

#include <cmath>
#include <memory>
#include <sstream>

#include <Scene/GameObject/GameObject.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/GUI/Elements/GUIButton.hpp>

namespace sp {
	FPSCounter::FPSCounter(GameObject * const gameObject) : GameObjectComponent(gameObject) {
		_timeSinceLastRender = 0.0F;
	}

	void FPSCounter::update(SpFloat const deltaTime) {
		_timeSinceLastRender += deltaTime;
		_numberOfFrames++;

		// Render text
		guiButton(_gameObjectOwner->getSceneRef()->getRenderContext(), _settings);

		_timeSinceLastRender = 0.0F;
		_numberOfFrames = 0;
	}
}
