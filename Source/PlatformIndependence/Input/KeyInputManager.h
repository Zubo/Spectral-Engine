#pragma once

#include <map>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "PlatformIndependence/Input/KeyCode.h"

namespace sp {
	class KeyInputManager {
	public:
		KeyInputManager(GLFWwindow * const window);

	public:
		bool keyPressed(KeyCode const keyCode);
		void update();

	private:
		GLFWwindow * window;
		std::map<KeyCode, bool> _keyPressedMap;
	};
}
