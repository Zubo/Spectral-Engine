#include <glad/glad.h>
#include <memory>

#include <Scene/Components/Camera.hpp>
#include <Scene/GameObject/GameObject.hpp>
#include <Scene/Components/Material.hpp>
#include <Scene/Components/Renderer.hpp>
#include <Scene/Components/Transform.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/Shader/ShaderProgram.hpp>
#include <Render/RenderDataContainer.hpp>
#include <Render/RenderContext.hpp>

namespace sp {
	Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
	}

	void Renderer::initRenderer(SpUnsigned const meshId) {
		GameObject const * gameObjectOwner = _gameObjectOwner;
		SpInt const gameObjectId = gameObjectOwner->getId();
		bool const isActive = gameObjectOwner->getIsActive();
		bool const isStatic = false;
		RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
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
			RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
			renderContext.updatePosition(gameObjectId, position);
		}
	}

	void Renderer::onRotationUpdated(Vector3 const & rotation) {
		if (hasMesh()) {
			SpInt const gameObjectId = _gameObjectOwner->getId();
			RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
			renderContext.saveRotation(gameObjectId, rotation);
		}
	}

	void Renderer::onScaleUpdated(Vector3 const & scale) {
		if (hasMesh()) {
			SpInt const gameObjectId = _gameObjectOwner->getId();
			RenderContext & renderContext{ _gameObjectOwner->getSceneRef()->getRenderContext() };
			renderContext.updateScale(gameObjectId, scale);
		}
	}

	bool Renderer::hasMesh() const {
		OptionalRef<Renderer> rendererRef = _gameObjectOwner->getComponent<Renderer>();
		return (bool)rendererRef.HasRef();
	}
}
