#include "Game/Components/GameObjectComponent.h"
#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	SpInt GameObject::_nextId{ 0 };

	GameObject::GameObject() {
		_id = (++GameObject::_nextId);
		_isActive = true;
	}

	void GameObject::bindToScene(Scene & scene) {
		_sceneOptionalRef = scene;
	}

	OptionalRef<Scene> const & GameObject::GetSceneRef() const {
		return _sceneOptionalRef;
	}

	void GameObject::updateComponents(SpFloat const deltaTime) {
		for (auto & component : _components) {
			component->update(deltaTime);
		}
	}
}
