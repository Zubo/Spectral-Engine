#include "Render/Renderer.h"

#include "Core/Math/Direction.h"
#include "glad/glad.h"
#include "Render/CameraData.h"
#include "Render/RenderData.h"
#include "Render/LightDataContainer.h"
#include "Render/RenderDataContainer.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	class Matrix4x4;
	class Vector3;

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

	inline void updateLights(ShaderProgram const & shaderProgram) {
		LightDataContainer const & lightDataContainer = LightDataContainer::getInstance();
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

	void renderAll() {
		RenderDataContainer & renderDataContainer = RenderDataContainer::getInstance();

		auto iterator = renderDataContainer.getRenderDataMap().cbegin();
		auto end = renderDataContainer.getRenderDataMap().cend();

		Matrix4x4 const projectionMatrix = CameraData::GetProjectionMatrix();
		Matrix4x4 const viewMatrix = CameraData::GetViewMatrix();
		Vector3 const cameraPos = CameraData::getTranslation();
		bool const cameraDataChanged = CameraData::getDataChanged();
		Vector3 const cameraRotation = CameraData::getRotation();

		for (iterator; iterator != end; ++iterator) {
			RenderData const & renderData = iterator->second;

			renderData.RenderShaderProgram.use();

			updateLights(renderData.RenderShaderProgram);

			if (renderData.ModelMatrixChanged) {
				Matrix4x4 const modelMatrix = renderData.GetModelMatrix();
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
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		lightDataContainer.setNumberOfLightsChangedToFalse();
		lightDataContainer.setAllLightDataChangedToFalse();
		CameraData::setDataChangedToFalse();
	}
}
