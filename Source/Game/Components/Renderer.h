#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Interface/IRenderer.h"


namespace sp {
	class GameObject;
	class Mesh;

	class Renderer : public GameObjectComponent, public IRenderer {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(Mesh const & renderData);
		void render() const override;

	private:
		void initializeRenderData(Mesh const & renderData);

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;
	};
}
