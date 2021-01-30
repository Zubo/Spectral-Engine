#include <glad/glad.h>

#include <Core/Event/Message/EventMessage.h>
#include <Core/Event/Message/Messages/ViewportChangedMessage.h>
#include <Render/Mesh.h>
#include <Render/MeshContainer.h>
#include <Render/RenderContext.h>
#include <Render/RenderData.h>

namespace sp {
	RenderContext::RenderContext(SpInt const id) : _id{ id } {
	}

	SpInt RenderContext::getId() {
		return _id;
	}

	RenderDataContainer const & RenderContext::getRenderDataContainer() const {
		return _renderDataContainer;
	}

	RenderDataContainer & RenderContext::getRenderDataContainer() {
		return _renderDataContainer;
	}

	LightDataContainer const & RenderContext::getLightDataContainer() const {
		return _lightDataContainer;
	}

	LightDataContainer & RenderContext::getLightDataContainer() {
		return _lightDataContainer;
	}

	CameraData const & RenderContext::getCameraData() const {
		return _cameraData;
	}

	CameraData & RenderContext::getCameraData() {
		return _cameraData;
	}

	std::unique_ptr<SpWindow> const & RenderContext::getWindow() const {
		return _spWindowUnique;
	}

	void RenderContext::bindWindow(std::unique_ptr<SpWindow> spWindowUnique, IEventContext & eventContext) {
		_spWindowUnique = std::move(spWindowUnique);

		_viewportChangedEventBinding.bind(eventContext, EventMessageType::ViewportChanged,
			[](EventMessage & message) {
			ViewportChangedMessage & viewportChangedMessage{ dynamic_cast<ViewportChangedMessage &>(message) };
			glViewport(0, 0, viewportChangedMessage.getWidth(), viewportChangedMessage.getHeight());
		});
	}

	void RenderContext::createRenderData(SpInt const gameObjectId, bool const active, SpUnsigned const meshId, bool const isStatic) {
		RenderData renderData{ gameObjectId, active, isStatic };
		renderData.GameObjectId = gameObjectId;

		_renderDataContainer.saveRenderData(renderData);
		updateObjectMesh(gameObjectId, meshId, isStatic);
	}

	void RenderContext::updateObjectMesh(SpInt const gameObjectId, SpUnsigned const meshId, bool isStatic) {
		RenderData renderData = _renderDataContainer.getRenderData(gameObjectId);

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

		_renderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updateShaderProgram(SpInt const gameObjectId, ShaderProgram const shaderProgram) {
		RenderData renderData = _renderDataContainer.getRenderData(gameObjectId);

		renderData.RenderShaderProgram = shaderProgram;

		_renderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updatePosition(SpInt const gameObjectId, Vector3 const & position) {
		RenderData renderData = _renderDataContainer.getRenderData(gameObjectId);
		renderData.Position = position;
		renderData.ModelMatrixChanged = true;
		_renderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::saveRotation(SpInt const gameObjectId, Vector3 const & rotationEuler) {
		RenderData renderData = _renderDataContainer.getRenderData(gameObjectId);
		renderData.RotationEuler = rotationEuler;
		renderData.ModelMatrixChanged = true;
		_renderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updateScale(SpInt const gameObjectId, Vector3 const & scale) {
		RenderData renderData = _renderDataContainer.getRenderData(gameObjectId);
		renderData.Scale = scale;
		renderData.ModelMatrixChanged = true;
		_renderDataContainer.saveRenderData(renderData);
	}

	void RenderContext::updateTextureId(SpInt const gameObjectId, SpUnsigned const textureId, SpUnsigned const textureIdIndex) {
		RenderData renderData = _renderDataContainer.getRenderData(gameObjectId);
		renderData.TextureIds[textureIdIndex] = textureId;
		_renderDataContainer.saveRenderData(renderData);
	}
}
