#pragma once

#include <glad/glad.h>
#include <Core/Math/Matrix4x4.hpp>
#include <Core/Math/Direction.hpp>
#include <Render/GUI/TextRenderer.hpp>
#include <Render/RenderContext.hpp>
#include <Render/RenderData.hpp>

namespace sp {
	inline void updateCamera(
		ShaderProgram const & shaderProgram,
		Matrix4x4 const & viewMatrix,
		Matrix4x4 const & projectionMatrix,
		Vector3 const & cameraPos,
		Vector3 const & cameraRotation) {
		SpString const & projectionMatrixUniformName = "projectionMatrix";
		shaderProgram.setMatrix4fv(projectionMatrixUniformName, projectionMatrix.getValuePtr());

		SpString const & viewMatrixUniformName = "viewMatrix";
		shaderProgram.setMatrix4fv(viewMatrixUniformName, viewMatrix.getValuePtr());

		SpString const & cameraPositionUniformName = "cameraPos";
		shaderProgram.setVec3(cameraPositionUniformName, cameraPos.X, cameraPos.Y, cameraPos.Z);

		SpString const & cameraDirectionUniformName = "cameraDir";
		Vector3 const cameraDirection = getDirection(cameraRotation.X, cameraRotation.Y);
		shaderProgram.setVec3(cameraDirectionUniformName, cameraDirection.X, cameraDirection.Y, cameraDirection.Z);
	}

	inline void bindTextures(RenderData const & renderData) {
		for (SpInt i = 0; i < MAX_NUMBER_OF_TEXTURES; ++i) {
			SpInt const textureUnit = GL_TEXTURE0 + i;
			glActiveTexture(textureUnit);

			SpUnsigned const textureId = renderData.TextureIds[i];
			glBindTexture(GL_TEXTURE_2D, textureId);
		}
	}

	inline void unbindAllTextures() {
		for (SpInt i = 0; i < MAX_NUMBER_OF_TEXTURES; ++i) {
			SpInt const textureUnit = GL_TEXTURE0 + i;
			glActiveTexture(textureUnit);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	inline void updateLights(LightDataContainer const & lightDataContainer, ShaderProgram const & shaderProgram) {
		std::unordered_map<int, LightData> const & lightDataMap = lightDataContainer.getLightDataMap();
		SpInt index = 0;
		bool const numberOfLightsChanged = lightDataContainer.getNumberOfLightsChanged();

		for (auto const & lightDataMapEntry : lightDataMap) {
			LightData const & lightData = lightDataMapEntry.second;
			if (numberOfLightsChanged || lightData.Changed) {
				SpString const indexStr = std::to_string(index);
				SpString const variableAccessPrefix = "lightArray[" + indexStr + "]";
				shaderProgram.setInt(variableAccessPrefix + ".lightType", (int)lightData.Type);
				shaderProgram.setVec3(variableAccessPrefix + ".color",
					lightData.Color.X, lightData.Color.Y, lightData.Color.Z);
				shaderProgram.setVec3(variableAccessPrefix + ".position",
					lightData.Position.X, lightData.Position.Y, lightData.Position.Z);
				shaderProgram.setVec3(variableAccessPrefix + ".direction",
					lightData.Direction.X, lightData.Direction.Y, lightData.Direction.Z);
			}

			++index;
		}

		SpInt const numberOfLights = static_cast<SpInt>(lightDataMap.size());
		shaderProgram.setInt("numberOfLights", numberOfLights);
	}

	inline void renderScene(RenderDataContainer const & renderDataContainer, CameraData const & cameraData, LightDataContainer const & lightDataContainer) {
		Matrix4x4 const projectionMatrix = cameraData.GetProjectionMatrix();
		Matrix4x4 const viewMatrix = cameraData.GetViewMatrix();
		Vector3 const cameraPos = cameraData.getTranslation();
		bool const cameraDataChanged = cameraData.getDataChanged();
		Vector3 const cameraRotation = cameraData.getRotation();

		auto iterator = renderDataContainer.getRenderDataMap().begin();
		auto end = renderDataContainer.getRenderDataMap().end();

		for (; iterator != end; ++iterator) {
			RenderData const & renderData = iterator->second;

			renderData.DepthTest ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);

			renderData.RenderShaderProgram.use();

			updateLights(lightDataContainer, renderData.RenderShaderProgram);

			if (renderData.ModelMatrixChanged) {
				Matrix4x4 const modelMatrix = renderData.getModelMatrix();
				SpString const & modelMatrixUniformName = "modelMatrix";
				renderData.RenderShaderProgram.setMatrix4fv(modelMatrixUniformName, modelMatrix.getValuePtr());
			}

			if (cameraDataChanged) {
				updateCamera(renderData.RenderShaderProgram, viewMatrix, projectionMatrix, cameraPos, cameraRotation);
			}

			bindTextures(renderData);

			glBindVertexArray(renderData.VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
	}

	void renderGUIDrawCalls(RenderContext & renderContext) {
		GUIDrawCallDataContainer & guiDrawCallDataContainer = renderContext.getGUIDrawCallDataContainer();
		std::queue<GUIDrawCallData> & drawCallDataQueue = guiDrawCallDataContainer.getDrawCallDataQueue();

		while (!drawCallDataQueue.empty()) {
			GUIDrawCallData const & drawCallData = drawCallDataQueue.front();
			
			std::visit([&renderContextConst = std::as_const(renderContext)](auto const & drawCallData) {
				drawCallData.render(renderContextConst);
			}, drawCallData);

			drawCallDataQueue.pop();
		}
	}

	inline void render(RenderContext & renderContext) {
		std::unique_ptr<SpWindow> const & contextSpWindow = renderContext.getWindow();

		if (contextSpWindow == nullptr) {
			return;
		}

		contextSpWindow->makeCurrentContext();
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		RenderDataContainer & renderDataContainer = renderContext.getRenderDataContainer();
		CameraData & cameraData = renderContext.getCameraData();
		LightDataContainer & lightDataContainer = renderContext.getLightDataContainer();

		renderScene(renderDataContainer, cameraData, lightDataContainer);

		renderGUIDrawCalls(renderContext);

		unbindAllTextures();
		renderDataContainer.resetAllChangedFlags();
		lightDataContainer.setNumberOfLightsChangedToFalse();
		lightDataContainer.setAllLightDataChangedToFalse();
		cameraData.setDataChangedToFalse();

		contextSpWindow->swapBuffers();
		contextSpWindow->pollEvents();
	}
}
