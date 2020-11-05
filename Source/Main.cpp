#include <iostream>
#include <memory>

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "Core/Utility/ResourcesPathProvider.h"
#include "Game/Initializers.h"
#include "Game/Scene/Scene.h"
#include "PlatformIndependence/Environment.h"
#include "PlatformIndependence/Input/Input.h"
#include "PlatformIndependence/SpType.h"
#include "PlatformIndependence/SpWindow.h"
#include "Render/TextRenderer.h"
#include "Render/RenderEngine.h"

int main(int argc, char** argv) {
	std::unique_ptr<sp::SpWindow> window = sp::SpWindow::create(800, 600);
	sp::Input::init(*window);

	if (window->initializedSuccessfuly() == false) {
		return -1;
	}

	std::cout << sizeof(sp::Vector3) << std::endl;

	sp::SpString const executablePath{ argv[0] };
	sp::SpString const rootPath{ executablePath.substr(0, executablePath.find_last_of(sp::Environment::FilePathSeparator())) };
	sp::ResourcesPathProvider::initializePaths(rootPath);
	sp::initScene();

	sp::TextRenderer textRenderer{ *window };
	textRenderer.init();

	sp::RenderEngine renderEngine;
	sp::Scene scene{ renderEngine, true };
	scene.getRenderContext().assignWindow(std::move(window));

	glfwSwapInterval(0);
	glEnable(GL_DEPTH_TEST);

	sp::SpFloat lastFrame = static_cast<float>(glfwGetTime());

	while (!window->shouldClose()) {
		sp::SpFloat currentFrame = static_cast<float>(glfwGetTime());
		sp::SpFloat deltaTime = currentFrame - lastFrame;
		scene.updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		window->update();
		sp::Input::update();
		
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderEngine.renderAllContexts();

		glfwSwapBuffers(window->getConcreteWindow());
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	glfwTerminate();

	return 0;
}
