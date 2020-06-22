#include <iostream>
#include <memory>

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "Core/Utility/ResourcesPathProvider.h"
#include "Game/Initializers.h"
#include "Game/Vertices.h"
#include "PlatformIndependence/Environment.h"
#include "PlatformIndependence/Input/Input.h"
#include "PlatformIndependence/SpType.h"
#include "PlatformIndependence/SpWindow.h"
#include "Render/Renderer.h"
#include "Render/TextRenderer.h"

#include "Core/Math/Vector3.h"
#include "Core/Math/Vector2.h"

int main(int argc, char** argv) {
	sp::SpWindow::init(800, 600);
	sp::SpWindow const * const window = sp::SpWindow::getInstance();
	sp::Input::init();

	if (window->initializedSuccessfuly() == false) {
		return -1;
	}

	std::cout << sizeof(sp::Vector3) << std::endl;

	sp::SpString const executablePath{ argv[0] };
	sp::SpString const rootPath{ executablePath.substr(0, executablePath.find_last_of(sp::Environment::FilePathSeparator())) };
	sp::ResourcesPathProvider::initializePaths(rootPath);
	sp::initScene(argv[0]);

	sp::TextRenderer textRenderer = sp::TextRenderer::getInstance();
	textRenderer.init();

	glfwSwapInterval(0);
	glEnable(GL_DEPTH_TEST);

	sp::SpFloat lastFrame = static_cast<float>(glfwGetTime());

	sp::SpFloat lastFPS = 0.0F;
	sp::SpFloat deltaTimeAccumulated = 0.0F;
	int frameCounter = 0;

	while (!window->shouldClose()) {
		sp::SpFloat currentFrame = static_cast<float>(glfwGetTime());
		sp::SpFloat deltaTime = currentFrame - lastFrame;
		deltaTimeAccumulated += deltaTime;
		sp::GameObject::updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		window->update();
		sp::Input::update();
		
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sp::renderAll();
		textRenderer.renderText(std::to_string(lastFPS), { 50.0F }, { 0.3F });

		glfwSwapBuffers(window->getConcreteWindow());
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		++frameCounter;

		if (deltaTimeAccumulated > 1.0F) {
			lastFPS = frameCounter / deltaTimeAccumulated;
			frameCounter = 0;
			deltaTimeAccumulated = 0.0F;
		}
	}

	glfwTerminate();

	return 0;
}
