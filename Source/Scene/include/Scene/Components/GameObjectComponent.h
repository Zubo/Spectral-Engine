#pragma once

#include <PlatformIndependence/SpType.h>

namespace sp {
	class GameObject;

	class GameObjectComponent {
	public:
		GameObjectComponent(GameObject * const gameObject);
		virtual void update(SpFloat const deltaTime);
		GameObject const * getGameObject() const;
		virtual ~GameObjectComponent();

	protected:
		GameObject * _gameObjectOwner;
	};
}
