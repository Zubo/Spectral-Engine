#include "PlatformIndependence/Input/Input.h"

#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "PlatformIndependence/SpWindow.h"
#include "PlatformIndependence/Input/MouseInputManager.h"
#include "PlatformIndependence/Input/KeyInputManager.h"

namespace sp {
	std::unique_ptr<MouseInputManager> Input::_mouseInputManagerUnique;
	std::unique_ptr<KeyInputManager> Input::_keyInputManagerUnique;

	void Input::init(SpWindow & spWindow) {
		Input::_mouseInputManagerUnique = std::make_unique<MouseInputManager>();

		glfwSetCursorPosCallback(spWindow.getConcreteWindow(),
			[](auto window, auto xpos, auto ypos) {
			Input::_mouseInputManagerUnique->updateMousePos((float)xpos, (float)ypos);
		});

		Input::_keyInputManagerUnique = std::unique_ptr<KeyInputManager>(new KeyInputManager{ spWindow.getConcreteWindow() });
	}

	bool Input::keyDown(KeyCode keyCode) {
		return Input::_keyInputManagerUnique->keyPressed(keyCode);
	}

	Vector2 Input::mouseAxis() {
		return Vector2{ Input::_mouseInputManagerUnique->_xDelta, Input::_mouseInputManagerUnique->_yDelta };
	}

	void Input::update() {
		Input::_keyInputManagerUnique->update();
		Input::_mouseInputManagerUnique->update();
	}
}
