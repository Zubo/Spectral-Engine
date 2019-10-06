#include "Game/Components/GameObjectComponent.h"
#include "Game/GameObject/GameObject.h"

namespace sp {
	std::vector<GameObject *> GameObject::gameObjectCollection;
	int GameObject::nextId{ 0 };

	GameObject::GameObject() {
		this->id = (++GameObject::nextId);
		GameObject::gameObjectCollection.push_back(this);
	}

	GameObject::~GameObject() {
		int index = GameObject::getGameObjectIndex(this);
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

	int GameObject::getGameObjectIndex(GameObject *gameObject) {
		for (unsigned int i = 0; i < GameObject::gameObjectCollection.size(); ++i) {
			if (GameObject::gameObjectCollection.at(i) == gameObject) {
				return i;
			}
		}

		return -1;
	}
}
