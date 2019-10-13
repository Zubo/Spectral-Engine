#include "Render/RenderDataUpdate.h"

#include "glad/glad.h"
#include "Render/Mesh.h"
#include "Render/MeshContainer.h"
#include "Render/RenderData.h"
#include "Render/RenderDataContainer.h"
#include "Render/Shader/ShaderProgram.h"

void sp::createRenderData(int const gameObjectId, bool const active, unsigned int const meshId, bool const isStatic) {
	RenderData renderData{ gameObjectId, active, isStatic };
	renderData.gameObjectId = gameObjectId;

	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
	renderDataContainer.updateRenderData(renderData);
}

void sp::updateObjectMesh(int const gameObjectId, unsigned int const meshId, bool isStatic) {
	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
	RenderData renderData = renderDataContainer.getRenderData(gameObjectId);

	glGenVertexArrays(1, &renderData.VAO);
	glBindVertexArray(renderData.VAO);

	glGenBuffers(1, &renderData.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, renderData.VBO);

	Mesh const & mesh = MeshContainer::getMesh(meshId);
	int const stride = mesh.getStride() * sizeof(float);
	int attribArrayIndex = 0;

	glVertexAttribPointer(attribArrayIndex, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
	glEnableVertexAttribArray(attribArrayIndex++);
	int step = 3;

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

	int draw = (isStatic) ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW;
	glBufferData(GL_ARRAY_BUFFER, mesh.getDataArraySize() * sizeof(float), mesh.getDataArray(), draw);

	glGenBuffers(1, &renderData.EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderData.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.getIndexCount() * sizeof(int), mesh.getIndexArray(), draw);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	renderDataContainer.updateRenderData(renderData);
}

void sp::updateShaderProgram(int const gameObjectId, ShaderProgram const shaderProgram) {
	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
	RenderData renderData = renderDataContainer.getRenderData(gameObjectId);

	renderData.shaderProgram = shaderProgram;

	renderDataContainer.updateRenderData(renderData);
}

void sp::updateTranslationMatrix(int const gameObjectId, Matrix4x4 const & matrix) {
	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
	RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
	renderData.translationMatrix = matrix;
	renderDataContainer.updateRenderData(renderData);
}

void sp::updateRotationMatrix(int const gameObjectId, Matrix4x4 const & matrix) {
	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
	RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
	renderData.roatationMatrix = matrix;
	renderDataContainer.updateRenderData(renderData);
}

void sp::updateScaleMatrix(int const gameObjectId, Matrix4x4 const & matrix) {
	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
	RenderData renderData = renderDataContainer.getRenderData(gameObjectId);
	renderData.scaleMatrix = matrix;
	renderDataContainer.updateRenderData(renderData);
}
