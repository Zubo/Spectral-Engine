#pragma once

#include <unordered_map>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "PlatformIndependence/Input/KeyCode.h"

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
