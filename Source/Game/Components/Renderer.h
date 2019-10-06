#pragma once

#include "Game/Components/GameObjectComponent.h"
#include "Game/Components/Interface/IRenderer.h"
#include "Render/RenderData.h"


namespace sp {
	class GameObject;

	class Renderer : public GameObjectComponent, public IRenderer {
	public:
		Renderer(GameObject * const gameObjectOwner);
		void initRenderer(RenderData const & renderData);
		void render() const override;

	private:
		void initializeRenderData(RenderData const & renderData);

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;
	};
}
