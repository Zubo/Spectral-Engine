#include <GLFW/glfw3.h>
#include <PlatformIndependence/Input/KeyInputManager.hpp>

sp::KeyInputManager::KeyInputManager(GLFWwindow * window) : window{ window } {
}

bool sp::KeyInputManager::keyPressed(KeyCode const keyCode) {
	return _keyPressedMap[keyCode];
}

void sp::KeyInputManager::update() {
	for (auto i = GLFW_KEY_SPACE; i < GLFW_KEY_GRAVE_ACCENT; ++i) {
		_keyPressedMap[(KeyCode)i] = glfwGetKey(window, i);
	}
}
