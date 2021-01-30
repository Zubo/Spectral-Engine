#pragma once

#include <memory>
#include <vector>

#include "Core/Event/EventContext.h"
#include "Scene/GameObject/GameObject.h"
#include "PlatformIndependence/SpType.h"
#include "PlatformIndependence/Input/Input.h"
#include "Render/RenderContext.h"
#include "Render/RenderEngine.h"

namespace sp {
	class GameObject;

	class Scene {
	public:
		Scene(RenderEngine & renderEngine, bool const isMainScene);

	public:
		void updateGameObjects(SpFloat const deltaTime);
		std::vector< std::unique_ptr<GameObject> > const & getGameObjectCollection();
		void insertGameObject(std::unique_ptr<GameObject> gameObjectUnique);
		RenderContext & getRenderContext();
		RenderContext const & getRenderContext() const;
		Input const & getInput() const;
		Input & getInput();
		GameObject & createGameObject();
		void assignWindow(std::unique_ptr<SpWindow> window);

	private:
		EventContext _eventContext;
		SpInt getGameObjectIndex(std::unique_ptr<GameObject> const & gameObjectUnique) const;
		std::vector< std::unique_ptr<GameObject> > _gameObjectCollection;
		RenderContext & _renderContext;
	};
}
