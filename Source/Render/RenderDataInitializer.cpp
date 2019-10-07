#include "Render/RenderDataInitializer.h"

#include "glad/glad.h"
#include "Render/Mesh.h"
#include "Render/RenderData.h"
#include "Render/RenderDataContainer.h"
#include "Render/Shader/ShaderProgram.h"

void sp::initializeRenderData(int const gameObjectId, ShaderProgram const shaderProgram, bool const active, bool isStatic, Mesh const & mesh) {
	RenderData renderData{ gameObjectId, shaderProgram, active, isStatic };

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
	renderDataContainer.updateRenderData(gameObjectId, renderData);
}
