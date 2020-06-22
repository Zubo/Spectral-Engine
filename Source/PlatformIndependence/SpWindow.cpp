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

	sp::SpWindow::SpWindow(SpInt const width, SpInt const height) : width{ width }, height{ height }, initialized{ false } {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->concreteWindow = glfwCreateWindow(width, height, "Spectral Engine", NULL, NULL);

		if (this->concreteWindow == nullptr) {
			std::cout << "Failed to create GLFW window." << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(this->concreteWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD." << std::endl;
			return;
		}

		glViewport(0, 0, width, height);

		glfwSetFramebufferSizeCallback(this->concreteWindow,
			[](GLFWwindow * window, SpInt width, SpInt height) {
			glViewport(0, 0, width, height);
		});

		glfwSetInputMode(this->concreteWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		this->initialized = true;
	}

	void sp::SpWindow::update() const {
		if (glfwGetKey(this->concreteWindow, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(this->concreteWindow, true);
		}
	}

	bool const sp::SpWindow::initializedSuccessfuly() const {
		return this->initialized;
	}

	bool const sp::SpWindow::shouldClose() const {
		return glfwWindowShouldClose(this->concreteWindow);
	}

	GLFWwindow * const sp::SpWindow::getConcreteWindow() const {
		return this->concreteWindow;
	}
}
