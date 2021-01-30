#pragma once

#include <unordered_map>

#include <PlatformIndependence/Input/KeyCode.h>

struct GLFWwindow;

namespace sp {
	class KeyInputManager {
	public:
		KeyInputManager(GLFWwindow * window);

	public:
		bool keyPressed(KeyCode const keyCode);
		void update();

	private:
		GLFWwindow * window;
		std::unordered_map<KeyCode, bool> _keyPressedMap;
	};
}
