#include <PlatformIndependence/SpWindow.hpp>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

#include <PlatformIndependence/SpWindow.hpp>

namespace sp {
	bool SpWindow::_GLFWInitialized{ false };
	bool SpWindow::_gladInitialized{ false };

	std::unique_ptr<SpWindow> SpWindow::create(SpInt const width, SpInt const height, bool const isMainWindow) {
		if (!_GLFWInitialized) {
			initGLFW();
		}

		GLFWwindow * const concreteWindow{ glfwCreateWindow(width, height, "Spectral Engine", NULL, NULL) };

		if (concreteWindow == nullptr) {
			std::cout << "Failed to create GLFW window." << std::endl;
			return nullptr;
		}

		std::unique_ptr<SpWindow> windowUnique(new SpWindow(width, height, isMainWindow, concreteWindow));
		
		glfwSetWindowUserPointer(windowUnique->_concreteWindow, windowUnique.get());

		if (!_gladInitialized) {
			glfwMakeContextCurrent(windowUnique->_concreteWindow);
			initGlad();
		}

		return windowUnique;
	}

	void SpWindow::initGLFW() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		_GLFWInitialized = true;
	}

	void SpWindow::initGlad() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD." << std::endl;
			return;
		}

		_gladInitialized = true;
	}

	SpWindow::~SpWindow() {
		if (_concreteWindow) {
			glfwDestroyWindow(_concreteWindow);
		}

		if (_isMainWindow) {
			glfwTerminate();
		}
	}

	SpWindow::SpWindow(SpInt const width, SpInt const height, bool const isMainWindow, GLFWwindow * const concreteWindow) :
			_width{ width },
			_height{ height },
			_concreteWindow{ concreteWindow },
			_isMainWindow{ isMainWindow } {
		_inputUnique = std::make_unique<Input>(*concreteWindow);
	}

	void SpWindow::update() const {
		if (glfwGetKey(_concreteWindow, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(_concreteWindow, true);
		}
	}

	bool SpWindow::shouldClose() const {
		return glfwWindowShouldClose(_concreteWindow);
	}

	void SpWindow::setCursorEnabled(bool const cursorEnabled) const {
		auto inputModeCursorArg{ (cursorEnabled) ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED };
		glfwSetInputMode(_concreteWindow, GLFW_CURSOR, inputModeCursorArg);
	}

	Input const & SpWindow::getInput() const {
		return *_inputUnique;
	}

	Input & SpWindow::getInput() {
		return *_inputUnique;
	}

	void SpWindow::registerSetFramebufferSizeCallback(SetFramebufferSizeCallback callback) {
		_setFramebufferSizeCallback = callback;

		glfwSetFramebufferSizeCallback(_concreteWindow,
			[](GLFWwindow * window, SpInt width, SpInt height) {
			SpWindow * spWindow = static_cast<SpWindow*>(glfwGetWindowUserPointer(window));
			spWindow->_setFramebufferSizeCallback(width, height);
		});
	}
	
	void sp::SpWindow::makeCurrentContext() const {
		glfwMakeContextCurrent(_concreteWindow);
	}

	void SpWindow::swapBuffers() const {
		glfwSwapBuffers(_concreteWindow);
	}

	void SpWindow::pollEvents() const {
		glfwPollEvents();
	}
}
