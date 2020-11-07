#include <memory>

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

	sp::SpString const executablePath{ argv[0] };
	sp::SpString const rootPath{ executablePath.substr(0, executablePath.find_last_of(sp::Environment::FilePathSeparator())) };
	sp::ResourcesPathProvider::initializePaths(rootPath);

	sp::TextRenderer textRenderer{ *window };
	textRenderer.init();

	sp::RenderEngine renderEngine;
	sp::Scene scene{ renderEngine, true };
	scene.getRenderContext().assignWindow(std::move(window));
	sp::initScene(scene);

	sp::SpFloat lastFrame = static_cast<float>(glfwGetTime());

	sp::SpWindow const & mainWindow{ *scene.getRenderContext().getWindow() };

	while (!mainWindow.shouldClose()) {
		sp::SpFloat currentFrame = static_cast<float>(glfwGetTime());
		sp::SpFloat deltaTime = currentFrame - lastFrame;
		scene.updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		scene.getRenderContext().getWindow()->update();
		scene.getInput().update();
		
		renderEngine.renderAllContexts();
	}

	glfwTerminate();

	return 0;
}
