#include <chrono>
#include <memory>

#include <Core/Utility/ResourcesPathProvider.h>
#include <Scene/Scene/Scene.h>
#include <Scene/Initializers.h>
#include <PlatformIndependence/Environment.h>
#include <PlatformIndependence/SpType.h>
#include <PlatformIndependence/SpWindow.h>
#include <Render/TextRenderer.h>
#include <Render/RenderEngine.h>

int main(int argc, char** argv) {
	sp::SpString const executablePath{ argv[0] };
	sp::SpString const rootPath{ executablePath.substr(0, executablePath.find_last_of(sp::Environment::FilePathSeparator())) };
	sp::ResourcesPathProvider::initializePaths(rootPath);
	
	constexpr bool isMainWindow = true;
	std::unique_ptr<sp::SpWindow> window = sp::SpWindow::create(800, 600, isMainWindow);
	sp::TextRenderer::init();

	sp::RenderEngine renderEngine;
	sp::Scene scene{ renderEngine, true };

	scene.assignWindow(std::move(window));
	sp::initScene(scene);

	auto lastFrame = std::chrono::system_clock::now();

	sp::SpWindow & mainWindow{ *scene.getRenderContext().getWindow() };
	mainWindow.setCursorEnabled(false);

	while (!mainWindow.shouldClose()) {
		auto currentFrame = std::chrono::system_clock::now();
		sp::SpFloat const deltaTime =
			std::chrono::duration_cast<std::chrono::milliseconds>(currentFrame - lastFrame).count() / 1000.0F;
		scene.updateGameObjects(deltaTime);
		lastFrame = currentFrame;

		scene.getRenderContext().getWindow()->update();
		scene.getInput().update();
		
		renderEngine.renderAllContexts();
	}

	return 0;
}
