#include <Core/Event/IEventContext.hpp>
#include <Core/Utility/WindowEventBinding.hpp>
#include <Scene/Scene/Scene.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Scene/Scene/Scene.hpp>

namespace sp {
	Scene::Scene(RenderEngine & renderEngine, bool const isMainScene) :
		_renderContext{ renderEngine.createContext(isMainScene) } {
	}

	void Scene::updateGameObjects(SpFloat const deltaTime) {
		for (auto & gameObject : _gameObjectCollection) {
			gameObject->updateComponents(deltaTime);
		}
	}

	std::vector< std::unique_ptr<GameObject> > const & Scene::getGameObjectCollection() {
		return Scene::_gameObjectCollection;
	}

	void Scene::insertGameObject(std::unique_ptr<GameObject> gameObjectUnique) {
		gameObjectUnique->bindToScene(*this);
		_gameObjectCollection.emplace_back(std::move(gameObjectUnique));
	}

	RenderContext & Scene::getRenderContext() {
		return _renderContext;
	}

	RenderContext const & Scene::getRenderContext() const {
		return _renderContext;
	}

	Input const & Scene::getInput() const {
		return _renderContext.getWindow()->getInput();
	}

	Input & Scene::getInput() {
		return _renderContext.getWindow()->getInput();
	}

	GameObject & Scene::createGameObject() {
		std::unique_ptr<GameObject> gameObjectUnique{ std::make_unique<GameObject>() };
		GameObject & gameObjectRef = *gameObjectUnique;

		_gameObjectCollection.emplace_back(std::move(gameObjectUnique));

		gameObjectRef.bindToScene(*this);

		return gameObjectRef;
	}

	void Scene::assignWindow(std::unique_ptr<SpWindow> window) {
		_renderContext.bindWindow(std::move(window), _eventContext);
		bindWindowToEventContext(*_renderContext.getWindow(), _eventContext);
	}

	SpInt Scene::getGameObjectIndex(std::unique_ptr<GameObject> const & gameObjectUnique) const {
		for (SpUnsigned i = 0; i < Scene::_gameObjectCollection.size(); ++i) {
			if (Scene::_gameObjectCollection.at(i) == gameObjectUnique) {
				return i;
			}
		}

		return -1;
	}
}
