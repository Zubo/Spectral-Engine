#include <glad/glad.h>
#include <memory>

#include "Game/Components/Camera.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Components/Material.h"
#include "Game/Components/Renderer.h"
#include "Game/Components/Transform.h"
#include "PlatformIndependence/SpString.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/RenderData.h"

namespace sp {
	Renderer::Renderer(GameObject * const gameObjectOwner) : GameObjectComponent(gameObjectOwner) {
	}

	void Renderer::initRenderer(RenderData const & renderData) {
		this->initializeRenderData(renderData);
	}

	void Renderer::render() const {
		auto material = this->gameObjectOwner->getComponent<Material>();

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

		if (std::shared_ptr<Material> materialShared = material.lock()) {
			materialShared->use(mvpMatrix, modelMatrix);
		
			if (auto shaderProgram = materialShared->getShaderProgram().lock()) {
				shaderProgram->use();
				shaderProgram->setVec3("cameraPos", cameraPos.x, cameraPos.y, cameraPos.z);
				shaderProgram->setVec3("cameraDir", cameraDir.x, cameraDir.y, cameraDir.z);
			}
		}

		glBindVertexArray(this->VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	void Renderer::initializeRenderData(RenderData const & renderData) {
		glGenVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);

		glGenBuffers(1, &this->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

		int const stride = renderData.getStride() * sizeof(float);
		int attribArrayIndex = 0;

		glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
		glEnableVertexAttribArray(attribArrayIndex++);
		int step = 3;

		if (renderData.hasNormalCoords()) {
			void const * const stepPointer = (void *)(step * sizeof(float));
			glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, stepPointer);
			glEnableVertexAttribArray(attribArrayIndex++);
			step += 3;
		}

		if (renderData.hasUVCoords()) {
			void const * const stepPointer = (void *)(step * sizeof(float));
			glVertexAttribPointer(attribArrayIndex, 2, GL_FLOAT, GL_FALSE, stride, stepPointer);
			glEnableVertexAttribArray(attribArrayIndex++);
			step += 2;
		}

		glBufferData(GL_ARRAY_BUFFER, renderData.getDataArraySize() * sizeof(float), renderData.getDataArray(), GL_STATIC_DRAW);
	
		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, renderData.getIndexCount() * sizeof(int), renderData.getIndexArray(), GL_STATIC_DRAW);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
