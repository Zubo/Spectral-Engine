#include <glad/glad.h>
#include <memory>

#include "Scene/Components/Camera.h"
#include "Scene/GameObject/GameObject.h"
#include "Scene/Components/Material.h"
#include "Scene/Components/Renderer.h"
#include "Scene/Components/Transform.h"
#include "PlatformIndependence/SpString.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/RenderDataUpdate.h"
#include "Render/RenderDataContainer.h"
#include "Render/RenderContext.h"

namespace sp {
	Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
	}

	void Renderer::initRenderer(SpUnsigned const meshId) {
		GameObject const * gameObjectOwner = _gameObjectOwner;
		SpInt const gameObjectId = gameObjectOwner->getId();
		bool const isActive = gameObjectOwner->getIsActive();
		bool const isStatic = false;
		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
		renderContext.createRenderData(gameObjectId, isActive, meshId, isStatic);

		OptionalRef<Transform> transformOptionalRef = _gameObjectOwner->getComponent<Transform>();
		if (transformOptionalRef.HasRef()) {
			RenderData renderData = renderContext.getRenderDataContainer().getRenderData(gameObjectId);
			renderData.Position = transformOptionalRef->getPosition();
			renderData.RotationEuler = transformOptionalRef->getRotationEuler();
			renderData.Scale = transformOptionalRef->getScale();
			renderContext.getRenderDataContainer().saveRenderData(renderData);
		}
	}

	Renderer::~Renderer() {
	}

	void Renderer::onPositionUpdated(Vector3 const & position) {
		if (hasMesh()) {
			SpInt const gameObjectId = _gameObjectOwner->getId();
			RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
			renderContext.updatePosition(gameObjectId, position);
		}
	}

	void Renderer::onRotationUpdated(Vector3 const & rotation) {
		if (hasMesh()) {
			SpInt const gameObjectId = _gameObjectOwner->getId();
			RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
			renderContext.saveRotation(gameObjectId, rotation);
		}
	}

	void Renderer::onScaleUpdated(Vector3 const & scale) {
		if (hasMesh()) {
			SpInt const gameObjectId = _gameObjectOwner->getId();
			RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };
			renderContext.updateScale(gameObjectId, scale);
		}
	}

	bool Renderer::hasMesh() const {
		OptionalRef<Renderer> rendererRef = _gameObjectOwner->getComponent<Renderer>();
		return (bool)rendererRef.HasRef();
	}
}
