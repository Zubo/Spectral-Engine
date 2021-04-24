#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include <Scene/Components/GameObjectComponent.hpp>
#include <Scene/Scene/Scene.hpp>
#include <Core/Utility/OptionalRef.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class GameObjectComponent;
	class Scene;

	class GameObject {
	public:
		GameObject();
		~GameObject() = default;

	public:
		inline SpInt getId() const {
			return _id;
		}

		inline bool getIsActive() const {
			return _isActive;
		}

		void bindToScene(Scene & scene);
		OptionalRef<Scene> const & getSceneRef() const;

		template <typename T>
		T& addComponent() {
			std::unique_ptr<GameObjectComponent> componentUnique{ new T{ this } };
			GameObjectComponent & component = *componentUnique;

			_components.push_back(std::move(componentUnique));

			return dynamic_cast<T &>(component);
		}

		template <typename T>
		OptionalRef<T> getComponent() const {
			for (auto const & compUnique : _components) {
				if (IsComponentOfType<T>(compUnique)) {
					return OptionalRef<T>(dynamic_cast<T &>(*compUnique));
				}
			}

			return OptionalRef<T>();
		}

		template <typename T>
		std::vector< OptionalRef<T> > getComponents() const {
			std::vector< OptionalRef<T> > componentsVector;

			for (auto & compUnique : _components) {
				if (IsComponentOfType<T>(compUnique)) {
					componentsVector.push_back(dynamic_cast<T &>(*compUnique));
				}
			}

			return componentsVector;
		}

		void updateComponents(SpFloat const deltaTime);

	private:
		template<typename T>
		bool IsComponentOfType(std::unique_ptr<GameObjectComponent> const & gameObjectComponentUnique) const {
			T * const casted = dynamic_cast<T*>(gameObjectComponentUnique.get());

			return casted != nullptr;
		}

	private:
		SpInt _id;
		bool _isActive;
		std::vector< std::unique_ptr<GameObjectComponent> > _components;
		OptionalRef<Scene> _sceneOptionalRef;

	private:
		static SpInt _nextId;
	};
}
