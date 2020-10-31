#include "Render/RenderDataUpdate.h"

#include "glad/glad.h"
#include "PlatformIndependence/SpType.h"
#include "Render/Mesh.h"
#include "Render/MeshContainer.h"
#include "Render/RenderData.h"
#include "Render/RenderDataContainer.h"
#include "Render/Shader/ShaderProgram.h"

namespace sp {

	void createRenderData(SpInt const gameObjectId, bool const active, SpUnsigned const meshId, bool const isStatic) {
		RenderData renderData{ gameObjectId, active, isStatic };
		renderData.GameObjectId = gameObjectId;

		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		renderDataContainer.saveRenderData(renderData);
		updateObjectMesh(gameObjectId, meshId, isStatic);
	}

	void updateObjectMesh(SpInt const gameObjectId, SpUnsigned const meshId, bool isStatic) {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		RenderData renderData = renderDataContainer.getRenderData(gameObjectId);

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

		renderDataContainer.saveRenderData(renderData);
	}

	void updateShaderProgram(SpInt const gameObjectId, ShaderProgram const shaderProgram) {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		RenderData renderData = renderDataContainer.getRenderData(gameObjectId);

		renderData.RenderShaderProgram = shaderProgram;

		renderDataContainer.saveRenderData(renderData);
	}

	void updatePosition(SpInt const gameObjectId, Vector3 const & position) {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
		renderData.Position = position;
		renderData.ModelMatrixChanged = true;
		renderDataContainer.saveRenderData(renderData);
	}

	void saveRotation(SpInt const gameObjectId, Vector3 const & rotationEuler) {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
		renderData.RotationEuler = rotationEuler;
		renderData.ModelMatrixChanged = true;
		renderDataContainer.saveRenderData(renderData);
	}

	void updateScale(SpInt const gameObjectId, Vector3 const & scale) {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
		renderData.Scale = scale;
		renderData.ModelMatrixChanged = true;
		renderDataContainer.saveRenderData(renderData);
	}

	void updateTextureId(SpInt const gameObjectId, SpUnsigned const textureId, SpUnsigned const textureIdIndex) {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();
		RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
		renderData.TextureIds[textureIdIndex] = textureId;
		renderDataContainer.saveRenderData(renderData);
	}
}
