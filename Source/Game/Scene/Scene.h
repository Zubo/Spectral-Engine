#pragma once

#include <memory>
#include <vector>

#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpType.h"
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

	private:
		SpInt getGameObjectIndex(std::unique_ptr<GameObject> const & gameObjectUnique) const;
		std::vector< std::unique_ptr<GameObject> > _gameObjectCollection;
		RenderContext & _renderContext;
	};
}
