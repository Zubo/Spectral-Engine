#include "Scene/Components/GameObjectComponent.h"

namespace sp {
	GameObjectComponent::GameObjectComponent(GameObject * const gameObjectOwner) :
		_gameObjectOwner{ gameObjectOwner } {
	}

	void GameObjectComponent::update(SpFloat const deltaTime) {
		(void)deltaTime;
	}

	GameObject const * GameObjectComponent::getGameObject() const {
		return _gameObjectOwner;
	}

	GameObjectComponent::~GameObjectComponent() {
	}
}
