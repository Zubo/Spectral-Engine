#include <iostream>
#include <memory>

#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "Core/Utility/ResourcesPathProvider.h"
#include "Game/Components/Interface/IRenderer.h"
#include "Game/Components/Material.h"
#include "Game/Components/Renderer.h"
#include "Game/Initializers.h"
#include "Game/Vertices.h"
#include "PlatformIndependence/Input/Input.h"
#include "PlatformIndependence/SpWindow.h"
#include "Render/Renderer.h"

#include "Core/Math/Vector3.h"


int main(int argc, char** argv) {
	sp::SpWindow::init(800, 600);
	sp::SpWindow const * const window = sp::SpWindow::getInstance();
	sp::Input::init();

	if (window->initializedSuccessfuly() == false) {
		return -1;
	}

	std::cout << sizeof(sp::Vector3) << std::endl;

	SpString const executablePath{ argv[0] };
	SpString const rootPath{ executablePath.substr(0, executablePath.find_last_of("\\")) };
	sp::ResourcesPathProvider::initializePaths(rootPath);
	sp::initScene(argv[0]);

	glfwSwapInterval(0);
	glEnable(GL_DEPTH_TEST);

	float lastFrame = static_cast<float>(glfwGetTime());

	while (!window->shouldClose()) {
		float currentFrame = static_cast<float>(glfwGetTime());
		float deltaTime = currentFrame - lastFrame;
		sp::GameObject::updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		window->update();
		sp::Input::update();
		
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*float oscilationFactor = (sin(currentFrame) / 2) + 0.5F;
		float color[3] = { 1.0F - oscilationFactor, oscilationFactor, 0.5 };*/

		/*std::vector<sp::GameObject *> gameObjectCollection = sp::GameObject::getGameObjectCollection();
		for (auto const & gameObject : gameObjectCollection) {
			auto rendererWeak = gameObject->getComponent<sp::Renderer>();
			if (auto rendererShared = rendererWeak.lock()) {
				rendererShared->render();
			}
		}
		for (auto const & gameObject : gameObjectCollection) {
			auto rendererWeak = gameObject->getComponent<sp::TextRenderer>();
			if (auto rendererShared = rendererWeak.lock()) {
				rendererShared->render();
			}
		}*/

		sp::renderAll();

		glfwSwapBuffers(window->getConcreteWindow());
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	glfwTerminate();

	return 0;
}
