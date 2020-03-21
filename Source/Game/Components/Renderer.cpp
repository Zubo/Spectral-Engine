#include <glad/glad.h>
#include <memory>

#include "Game/Components/Camera.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/Material.h"
#include "Game/Components/Renderer.h"
#include "Game/Components/Transform.h"
#include "PlatformIndependence/SpString.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/RenderDataUpdate.h"

namespace sp {
	Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
	}

	void Renderer::initRenderer(unsigned int const meshId) {
		GameObject const * const gameObjectOwner = this->gameObjectOwner;
		int const gameObjectId = gameObjectOwner->getId();
		bool const isActive = gameObjectOwner->getIsActive();
		bool const isStatic = false;
		createRenderData(gameObjectId, isActive, isStatic, meshId);
	}
}
