#pragma once

#include <Scene/Components/GameObjectComponent.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/GUI/Elements/Settings/GUIButtonSettings.hpp>

#define FPS_RENDER_PERIOD 0.35F

namespace sp {
	class FPSCounter : public GameObjectComponent {
	public:
		FPSCounter(GameObject * const gameObject);

	public:
		void update(SpFloat const deltaTime) override;

	private:
		SpFloat _timeSinceLastRender;
		SpInt _numberOfFrames = 0;
		GUIButtonSettings _settings{ Vector2::getVectorZero(), Vector2::getVectorOne() * 150, "Hello" };
	};
}
