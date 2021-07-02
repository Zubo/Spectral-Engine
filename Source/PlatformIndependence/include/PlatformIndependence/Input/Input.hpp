#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include <PlatformIndependence/Input/KeyCode.hpp>
#include <PlatformIndependence/Input/KeyInputManager.hpp>
#include <PlatformIndependence/Input/MouseInputManager.hpp>

struct GLFWwindow;

namespace sp {
	using MousePosCallbackFunction = std::function<void(float const posX, float const posY)>;

	class MouseInputManager;

	class Input {
	public:
		Input(GLFWwindow & spWindow);

	public:
		bool keyDown(KeyCode keyCode);
		SpFloat mouseAxisX() const;
		SpFloat mouseAxisY() const;
		SpFloat getMousePosX() const;
		SpFloat getMousePosY() const;
		void update();

	private:
		MouseInputManager _mouseInputManager;
		KeyInputManager _keyInputManager;
		
	private:
		static std::unordered_map<GLFWwindow *, MousePosCallbackFunction> _updateMousePosCallbackMap;
	};
}
