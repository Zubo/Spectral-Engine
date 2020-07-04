#include "SpWindow.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <ThirdParty/Glad/include/glad/glad.h>
#include <iostream>

#include "SpWindow.h"

namespace sp {
	sp::SpWindow * sp::SpWindow::windowInstance = nullptr;

	void sp::SpWindow::init(SpInt const width, SpInt const height) {
		SpWindow::windowInstance = new SpWindow(width, height);
	}

	sp::SpWindow * const sp::SpWindow::getInstance() {
		if (SpWindow::windowInstance == nullptr) {
			std::cerr << "Error: Trying to get unallocated window instance.";
		}

		return SpWindow::windowInstance;
	}

	sp::SpWindow::SpWindow(SpInt const width, SpInt const height) : _width{ width }, _height{ height }, _initialized{ false } {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		_concreteWindow = glfwCreateWindow(width, height, "Spectral Engine", NULL, NULL);

		if (_concreteWindow == nullptr) {
			std::cout << "Failed to create GLFW window." << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(_concreteWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD." << std::endl;
			return;
		}

		glViewport(0, 0, width, height);

		glfwSetFramebufferSizeCallback(_concreteWindow,
			[](GLFWwindow * window, SpInt width, SpInt height) {
			glViewport(0, 0, width, height);
		});

		glfwSetInputMode(_concreteWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		_initialized = true;
	}

	void sp::SpWindow::update() const {
		if (glfwGetKey(_concreteWindow, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(_concreteWindow, true);
		}
	}

	bool const sp::SpWindow::initializedSuccessfuly() const {
		return _initialized;
	}

	bool const sp::SpWindow::shouldClose() const {
		return glfwWindowShouldClose(_concreteWindow);
	}

	GLFWwindow * const sp::SpWindow::getConcreteWindow() const {
		return _concreteWindow;
	}
}
