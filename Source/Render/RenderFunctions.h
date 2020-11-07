#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Direction.h"
#include "Render/RenderContext.h"
#include "Render/RenderData.h"

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

			SpUnsigned textureId = renderData.TextureIds[i];
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

	inline void render(RenderContext & renderContext) {
		std::unique_ptr<SpWindow> const & contextSpWindow = renderContext.getWindow();

		if (contextSpWindow == nullptr) {
			return;
		}

		GLFWwindow * const glfwWindow = contextSpWindow->getConcreteWindow();
		glfwMakeContextCurrent(glfwWindow);

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		RenderDataContainer & renderDataContainer = renderContext.getRenderDataContainer();

		auto iterator = renderDataContainer.getRenderDataMap().begin();
		auto end = renderDataContainer.getRenderDataMap().end();

		CameraData & cameraData = renderContext.getCameraData();
		Matrix4x4 const projectionMatrix = cameraData.GetProjectionMatrix();
		Matrix4x4 const viewMatrix = cameraData.GetViewMatrix();
		Vector3 const cameraPos = cameraData.getTranslation();
		bool const cameraDataChanged = cameraData.getDataChanged();
		Vector3 const cameraRotation = cameraData.getRotation();

		for (iterator; iterator != end; ++iterator) {
			RenderData const & renderData = iterator->second;

			renderData.RenderShaderProgram.use();

			updateLights(renderContext.getLightDataContainer(), renderData.RenderShaderProgram);

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

		unbindAllTextures();
		renderDataContainer.resetAllChangedFlags();
		LightDataContainer & lightDataContainer = renderContext.getLightDataContainer();
		lightDataContainer.setNumberOfLightsChangedToFalse();
		lightDataContainer.setAllLightDataChangedToFalse();
		cameraData.setDataChangedToFalse();

		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
