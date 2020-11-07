#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "PlatformIndependence/Input/KeyCode.h"
#include "PlatformIndependence/Input/KeyInputManager.h"
#include "PlatformIndependence/Input/MouseInputManager.h"
#include "Core/Math/Vector2.h"

struct GLFWwindow;

namespace sp {
	using MousePosCallbackFunction = std::function<void(float const posX, float const posY)>;

	class MouseInputManager;

	class Input {
	public:
		Input(GLFWwindow & spWindow);

	public:
		bool keyDown(KeyCode keyCode);
		Vector2 mouseAxis();
		void update();

	private:
		MouseInputManager _mouseInputManager;
		KeyInputManager _keyInputManager;
		
	private:
		static std::unordered_map<GLFWwindow *, MousePosCallbackFunction> _updateMousePosCallbackMap;
	};
}
