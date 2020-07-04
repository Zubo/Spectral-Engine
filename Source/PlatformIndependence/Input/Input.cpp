#include "PlatformIndependence/Input/Input.h"

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "PlatformIndependence/SpWindow.h"
#include "PlatformIndependence/Input/MouseInputManager.h"
#include "PlatformIndependence/Input/KeyInputManager.h"

std::unique_ptr<sp::MouseInputManager> sp::Input::_mouseInputManagerUnique;
std::unique_ptr<sp::KeyInputManager> sp::Input::_keyInputManagerUnique;

void sp::Input::init() {
	Input::_mouseInputManagerUnique = std::make_unique<MouseInputManager>();

	GLFWwindow * window = SpWindow::getInstance()->getConcreteWindow();
	glfwSetCursorPosCallback(window,
		[](auto window, auto xpos, auto ypos) {
			Input::_mouseInputManagerUnique->updateMousePos((float)xpos, (float)ypos);
		});

	Input::_keyInputManagerUnique = std::unique_ptr<KeyInputManager>(new KeyInputManager{ window });
}

bool const sp::Input::keyDown(KeyCode keyCode) {
	return Input::_keyInputManagerUnique->keyPressed(keyCode);
}

sp::Vector2 const sp::Input::mouseAxis() {
	return Vector2{ Input::_mouseInputManagerUnique->_xDelta, Input::_mouseInputManagerUnique->_yDelta };
}

void sp::Input::update() {
	Input::_keyInputManagerUnique->update();
	Input::_mouseInputManagerUnique->update();
}
