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

	void Renderer::render() const {
		Matrix4x4 mvpMatrix;
		Matrix4x4 modelMatrix;
		Vector3 cameraPos{ 0.0F };
		Vector3 cameraDir{ 0.0F };
		auto transformWeak = this->gameObjectOwner->getComponent<Transform>();
		if (auto transformShared = transformWeak.lock()) {
			modelMatrix = transformShared->getTransformMatrix();

			auto cameraShared = Camera::getMainCamera();
			mvpMatrix = (cameraShared->getProjectionMatrix() * (cameraShared->getViewMatrix() * modelMatrix));
			if (auto cameraTransformShared = cameraShared->getGameObject()->getComponent<Transform>().lock()) {
				cameraPos = cameraTransformShared->getPosition();
				cameraDir = -cameraTransformShared->getDirection();
			}
		}

		auto material = this->gameObjectOwner->getComponent<Material>();
		if (std::shared_ptr<Material> materialShared = material.lock()) {
			materialShared->use(mvpMatrix, modelMatrix);
		
			if (auto shaderProgram = materialShared->getShaderProgram().lock()) {
				shaderProgram->use();
				shaderProgram->setVec3("cameraPos", cameraPos.x, cameraPos.y, cameraPos.z);
				shaderProgram->setVec3("cameraDir", cameraDir.x, cameraDir.y, cameraDir.z);
			}
		}

	}
}
