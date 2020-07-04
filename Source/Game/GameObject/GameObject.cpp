#include "Game/Components/GameObjectComponent.h"
#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	std::vector<GameObject *> GameObject::_gameObjectCollection;
	SpInt GameObject::_nextId{ 0 };

	GameObject::GameObject() {
		_id = (++GameObject::_nextId);
		_isActive = true;
		GameObject::_gameObjectCollection.push_back(this);
	}

	GameObject::~GameObject() {
		SpInt index = GameObject::getGameObjectIndex(this);
		auto iterator = GameObject::_gameObjectCollection.begin() + index;
		GameObject::_gameObjectCollection.erase(iterator);
	}

	void GameObject::updateComponents(SpFloat const deltaTime) {
		for (auto & component : _components) {
			component->update(deltaTime);
		}
	}

	void GameObject::updateGameObjects(SpFloat const deltaTime) {
		for (auto & gameObject : _gameObjectCollection) {
			gameObject->updateComponents(deltaTime);
		}
	}

	std::vector<GameObject*> GameObject::getGameObjectCollection() {
		return GameObject::_gameObjectCollection;
	}

	SpInt GameObject::getGameObjectIndex(GameObject *gameObject) {
		for (SpUnsigned i = 0; i < GameObject::_gameObjectCollection.size(); ++i) {
			if (GameObject::_gameObjectCollection.at(i) == gameObject) {
				return i;
			}
		}

		return -1;
	}
}
