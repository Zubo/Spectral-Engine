#pragma once

#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class MouseInputManager {
		friend class Input;

	public:
		MouseInputManager() = default;

	public:
		void update();
		void updateMousePos(SpFloat const xPosition, SpFloat const yPosition);

	private:
		SpFloat _xPosition = 0.0F;
		SpFloat _yPosition = 0.0F;
		SpFloat _xDelta = 0.0F;
		SpFloat _yDelta = 0.0F;
		bool _updated = false;
	};
}
