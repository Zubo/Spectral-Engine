#include "Game/Components/GameObjectComponent.h"
#include "Game/GameObject/GameObject.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	std::vector<GameObject *> GameObject::gameObjectCollection;
	SpInt GameObject::nextId{ 0 };

	GameObject::GameObject() {
		this->id = (++GameObject::nextId);
		this->isActive = true;
		GameObject::gameObjectCollection.push_back(this);
	}

	GameObject::~GameObject() {
		SpInt index = GameObject::getGameObjectIndex(this);
		auto iterator = GameObject::gameObjectCollection.begin() + index;
		GameObject::gameObjectCollection.erase(iterator);
	}

	void GameObject::updateComponents(float const deltaTime) {
		for (auto & component : this->components) {
			component->update(deltaTime);
		}
	}

	void GameObject::updateGameObjects(float const deltaTime) {
		for (auto & gameObject : gameObjectCollection) {
			gameObject->updateComponents(deltaTime);
		}
	}

	std::vector<GameObject*> GameObject::getGameObjectCollection() {
		return GameObject::gameObjectCollection;
	}

	SpInt GameObject::getGameObjectIndex(GameObject *gameObject) {
		for (SpUnsigned i = 0; i < GameObject::gameObjectCollection.size(); ++i) {
			if (GameObject::gameObjectCollection.at(i) == gameObject) {
				return i;
			}
		}

		return -1;
	}
}
