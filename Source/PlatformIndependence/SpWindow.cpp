#include "SpWindow.h"
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <ThirdParty/Glad/include/glad/glad.h>
#include <iostream>
#include <memory>

#include "PlatformIndependence/SpWindow.h"

namespace sp {
	bool SpWindow::_GLFWInitialized{ false };

	std::unique_ptr<SpWindow> SpWindow::create(SpInt const width, SpInt const height) {
		return std::unique_ptr<SpWindow>(new SpWindow(width, height));
	}

	SpWindow::~SpWindow() {
		if (_concreteWindow) {
			glfwDestroyWindow(_concreteWindow);
		}
	}

	SpWindow::SpWindow(SpInt const width, SpInt const height) : _width{ width }, _height{ height } {
		if (!_GLFWInitialized) {
			initGLFW();
			_GLFWInitialized = true;
		}

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

		_inputUnique = std::make_unique<Input>(*_concreteWindow);
	}

	void SpWindow::update() const {
		if (glfwGetKey(_concreteWindow, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(_concreteWindow, true);
		}
	}

	bool SpWindow::shouldClose() const {
		return glfwWindowShouldClose(_concreteWindow);
	}

	GLFWwindow * SpWindow::getConcreteWindow() const {
		return _concreteWindow;
	}

	Input const & SpWindow::getInput() const {
		return *_inputUnique;
	}

	Input & SpWindow::getInput() {
		return *_inputUnique;
	}

	void SpWindow::initGLFW() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
}
