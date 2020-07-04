#pragma once

#include <memory>
#include <vector>

#include "PlatformIndependence/SpType.h"

namespace sp {
	class GameObjectComponent;

	class GameObject {
	public:
		GameObject();
		~GameObject();

	public:
		inline SpInt const getId() const {
			return _id;
		}

		inline bool const getIsActive() const {
			return _isActive;
		}

		template <typename T>
		std::weak_ptr<T> addComponent() {
			std::shared_ptr<T> component = std::make_shared<T>(this);
			_components.push_back(std::static_pointer_cast<GameObjectComponent>(component));
			return std::weak_ptr<T>{ component };
		};

		template <typename T>
		std::weak_ptr<T> getComponent() const {
			for (auto const & comp : _components) {
				std::shared_ptr<T> componentT = std::dynamic_pointer_cast<T>(comp);
				if (componentT != nullptr) {
					return std::weak_ptr<T>{ componentT };
				}
			}

			return std::weak_ptr<T>{};
		};

		template <typename T>
		std::vector<std::weak_ptr<T>> getComponents() const {
			std::vector<std::weak_ptr<T>> componentsVector;

			for (auto & comp : _components) {
				std::shared_ptr<T> componentT = std::dynamic_pointer_cast<T>(comp);
				if (componentT != nullptr) {
					std::weak_ptr<T> componentWeak = std::weak_ptr<T>{ componentT };
					componentsVector.push_back(componentWeak);
				}
			}

			return componentsVector;
		}

		void updateComponents(SpFloat const deltaTime);
		static void updateGameObjects(SpFloat const deltaTime);
		static std::vector<GameObject *> getGameObjectCollection();


	private:
		SpInt _id;
		bool _isActive;
		std::vector<std::shared_ptr<GameObjectComponent>> _components;
		static SpInt getGameObjectIndex(GameObject *);
		static std::vector<GameObject *> _gameObjectCollection;
		static SpInt _nextId;
	};
}
