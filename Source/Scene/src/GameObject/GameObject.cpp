#include <Scene/Components/GameObjectComponent.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	SpInt GameObject::_nextId{ 0 };

	GameObject::GameObject() {
		_id = (++GameObject::_nextId);
		_isActive = true;
	}

	void GameObject::bindToScene(Scene & scene) {
		_sceneOptionalRef = scene;
	}

	OptionalRef<Scene> const & GameObject::getSceneRef() const {
		return _sceneOptionalRef;
	}

	void GameObject::updateComponents(SpFloat const deltaTime) {
		for (auto & component : _components) {
			component->update(deltaTime);
		}
	}
}
