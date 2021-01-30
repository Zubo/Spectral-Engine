#include <PlatformIndependence/Input/Input.hpp>

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace sp {
	std::unordered_map<GLFWwindow *, MousePosCallbackFunction> Input::_updateMousePosCallbackMap;

	Input::Input(GLFWwindow & spWindow) :
		_keyInputManager{ &spWindow } {

		_updateMousePosCallbackMap.emplace(
			&spWindow,
			[this](float const xPos, float const yPos) {
			_mouseInputManager.updateMousePos(xPos, yPos);
		});
		
		glfwSetCursorPosCallback(
			&spWindow,
			[](GLFWwindow * window, double xpos, double ypos) {
			_updateMousePosCallbackMap.at(window)(static_cast<float>(xpos), static_cast<float>(ypos));
		});
	}

	bool Input::keyDown(KeyCode keyCode) {
		return _keyInputManager.keyPressed(keyCode);
	}

	SpFloat Input::mouseAxisX()	{
		return _mouseInputManager._xDelta;
	}

	SpFloat Input::mouseAxisY()	{
		return _mouseInputManager._yDelta;
	}

	void Input::update() {
		_keyInputManager.update();
		_mouseInputManager.update();
	}
}
