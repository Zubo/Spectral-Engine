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
#include "Render/RenderDataContainer.h"

namespace sp {
	Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
	}

	void Renderer::initRenderer(SpUnsigned const meshId) {
		GameObject const * const gameObjectOwner = this->gameObjectOwner;
		int const gameObjectId = gameObjectOwner->getId();
		bool const isActive = gameObjectOwner->getIsActive();
		bool const isStatic = false;
		createRenderData(gameObjectId, isActive, meshId, isStatic);

		std::weak_ptr<Transform> transformWeak = this->gameObjectOwner->getComponent<Transform>();
		if (std::shared_ptr<Transform> transformShared = transformWeak.lock()) {
			RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
			RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
			renderData.position = transformShared->getPosition();
			renderData.rotationEuler = transformShared->getRotationEuler();
			renderData.scale = transformShared->getScale();
			renderDataContainer.saveRenderData(renderData);
		}
	}

	Renderer::~Renderer() {
	}

	void Renderer::onPositionUpdated(Vector3 const & position) {
		if (this->hasMesh()) {
			int const gameObjectId = gameObjectOwner->getId();
			updatePosition(gameObjectId, position);
		}
	}

	void Renderer::onRotationUpdated(Vector3 const & rotation) {
		if (this->hasMesh()) {
			int const gameObjectId = gameObjectOwner->getId();
			saveRotation(gameObjectId, rotation);
		}
	}

	void Renderer::onScaleUpdated(Vector3 const & scale) {
		if (this->hasMesh()) {
			int const gameObjectId = gameObjectOwner->getId();
			updateScale(gameObjectId, scale);
		}
	}

	bool const Renderer::hasMesh() const {
		std::weak_ptr<Renderer> rendererWeak = this->gameObjectOwner->getComponent<Renderer>();
		return (bool)rendererWeak.lock();
	}
}
