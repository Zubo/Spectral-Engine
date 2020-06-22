#pragma once

#include "Core/Math/Vector2.h"

namespace sp {
	class MouseInputManager {
		friend class Input;

	public:
		MouseInputManager() = default;

	public:
		void update();
		void updateMousePos(SpFloat const xPosition, SpFloat const yPosition);

	private:
		SpFloat xPosition = 0.0F;
		SpFloat yPosition = 0.0F;
		SpFloat xDelta = 0.0F;
		SpFloat yDelta = 0.0F;
		bool updated = false;
	};
}
