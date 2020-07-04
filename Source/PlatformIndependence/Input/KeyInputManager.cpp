#include "PlatformIndependence/Input/KeyInputManager.h"

sp::KeyInputManager::KeyInputManager(GLFWwindow * const window) : window{ window } {
}

bool sp::KeyInputManager::keyPressed(KeyCode const keyCode) {
	return this->_keyPressedMap[keyCode];
}

void sp::KeyInputManager::update() {
	for (auto i = GLFW_KEY_SPACE; i < GLFW_KEY_GRAVE_ACCENT; ++i) {
		this->_keyPressedMap[(KeyCode)i] = glfwGetKey(this->window, i);
	}
}
