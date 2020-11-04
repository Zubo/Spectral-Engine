#include "glad/glad.h"
#include "Render/Mesh.h"
#include "Render/MeshContainer.h"
#include "Render/RenderContext.h"
#include "Render/RenderData.h"

namespace sp {
	RenderContext::RenderContext(SpInt const id) : Id{ id } {
	}

	std::unique_ptr<SpWindow> const & RenderContext::getWindow() const {
		return _spWindowUnique;
	}

	void RenderContext::assignWindow(std::unique_ptr<SpWindow> spWindowUnique) {
		_spWindowUnique = std::move(spWindowUnique);
	}

	void RenderContext::createRenderData(SpInt const gameObjectId, bool const active, SpUnsigned const meshId, bool const isStatic) {
		RenderData renderData{ gameObjectId, active, isStatic };
		renderData.GameObjectId = gameObjectId;

		RenderDataContainer.saveRenderData(renderData);
		updateObjectMesh(gameObjectId, meshId, isStatic);
	}

	void RenderContext::updateObjectMesh(SpInt const gameObjectId, SpUnsigned const meshId, bool isStatic) {
		RenderData renderData = RenderDataContainer.getRenderData(gameObjectId);

		glGenVertexArrays(1, &renderData.VAO);
		glBindVertexArray(renderData.VAO);

		glGenBuffers(1, &renderData.VBO);
		glBindBuffer(GL_ARRAY_BUFFER, renderData.VBO);

		Mesh const & mesh = MeshContainer::getMesh(meshId);
		SpInt const stride = mesh.getStride() * sizeof(float);
		SpInt attribArrayIndex = 0;

		glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
		glEnableVertexAttribArray(attribArrayIndex++);
		SpInt step = 3;

		if (mesh.hasNormalCoords()) {
			void const * const stepPointer = (void *)(step * sizeof(float));
			glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, stepPointer);
			glEnableVertexAttribArray(attribArrayIndex++);
			step += 3;
		}

		if (mesh.hasUVCoords()) {
			void const * const stepPointer = (void *)(step * sizeof(float));
			glVertexAttribPointer(attribArrayIndex, 2, GL_FLOAT, GL_FALSE, stride, stepPointer);
			glEnableVertexAttribArray(attribArrayIndex++);
			step += 2;
		}
		renderData.IsStatic = isStatic;
		SpInt draw = (isStatic) ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW;
		glBufferData(GL_ARRAY_BUFFER, mesh.getDataArraySize() * sizeof(float), mesh.getDataArray(), draw);

		glGenBuffers(1, &renderData.EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderData.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.getIndexCount() * sizeof(int), mesh.getIndexArray(), draw);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		RenderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updateShaderProgram(SpInt const gameObjectId, ShaderProgram const shaderProgram) {
		RenderData renderData = RenderDataContainer.getRenderData(gameObjectId);

		renderData.RenderShaderProgram = shaderProgram;

		RenderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updatePosition(SpInt const gameObjectId, Vector3 const & position) {
		RenderData renderData = RenderDataContainer.getRenderData(gameObjectId);
		renderData.Position = position;
		renderData.ModelMatrixChanged = true;
		RenderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::saveRotation(SpInt const gameObjectId, Vector3 const & rotationEuler) {
		RenderData renderData = RenderDataContainer.getRenderData(gameObjectId);
		renderData.RotationEuler = rotationEuler;
		renderData.ModelMatrixChanged = true;
		RenderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updateScale(SpInt const gameObjectId, Vector3 const & scale) {
		RenderData renderData = RenderDataContainer.getRenderData(gameObjectId);
		renderData.Scale = scale;
		renderData.ModelMatrixChanged = true;
		RenderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updateTextureId(SpInt const gameObjectId, SpUnsigned const textureId, SpUnsigned const textureIdIndex) {
		RenderData renderData = RenderDataContainer.getRenderData(gameObjectId);
		renderData.TextureIds[textureIdIndex] = textureId;
		RenderDataContainer.saveRenderData(renderData);
	}
}
