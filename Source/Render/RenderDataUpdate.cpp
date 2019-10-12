#include "Render/RenderDataUpdate.h"

#include "glad/glad.h"
#include "Render/Mesh.h"
#include "Render/RenderData.h"
#include "Render/RenderDataContainer.h"
#include "Render/Shader/ShaderProgram.h"

void sp::updateRenderData(int const gameObjectId, ShaderProgram const shaderProgram, bool const active, bool isStatic, Mesh const & mesh) {
	RenderData renderData{ gameObjectId, shaderProgram, active, isStatic };
	renderData.gameObjectId = gameObjectId;

	glGenVertexArrays(1, &renderData.VAO);
	glBindVertexArray(renderData.VAO);

	glGenBuffers(1, &renderData.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, renderData.VBO);

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

	RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();
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
