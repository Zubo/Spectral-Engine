#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Interface/IRenderer.h"


namespace sp {
	class GameObject;

	class Renderer : public GameObjectComponent, public IRenderer {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(unsigned int const meshId);
	};
}
