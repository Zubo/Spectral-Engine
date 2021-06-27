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
		guiButton(_gameObjectOwner->getSceneRef()->getRenderContext(), Vector2::getVectorOne() * 100.0F, Vector2{ 200.0F, 50.0F }, _settings);

		_timeSinceLastRender = 0.0F;
		_numberOfFrames = 0;
	}
}
