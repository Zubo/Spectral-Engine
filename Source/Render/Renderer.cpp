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
		shaderProgram.setVec3(cameraPositionUniformName, cameraPos.x, cameraPos.y, cameraPos.z);

		SpString const & cameraDirectionUniformName = "cameraDir";
		Vector3 const cameraDirection = getDirection(cameraRotation.x, cameraRotation.y);
		shaderProgram.setVec3(cameraDirectionUniformName, cameraDirection.x, cameraDirection.y, cameraDirection.z);
	}

	inline void bindTextures(RenderData const & renderData) {
		for (int i = 0; i < MAX_NUMBER_OF_TEXTURES; ++i) {
			int const textureUnit = GL_TEXTURE0 + i;
			glActiveTexture(textureUnit);

			unsigned int textureId = renderData.textureIds[i];
			glBindTexture(GL_TEXTURE_2D, textureId);
		}
	}

	inline void unbindAllTextures() {
		for (int i = 0; i < MAX_NUMBER_OF_TEXTURES; ++i) {
			int const textureUnit = GL_TEXTURE0 + i;
			glActiveTexture(textureUnit);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	inline void updateLights(ShaderProgram const & shaderProgram) {
		LightDataContainer const & lightDataContainer = LightDataContainer::getInstance();
		std::map<int, LightData> const & lightDataMap = lightDataContainer.getLightDataMap();
		int index = 0;
		bool const numberOfLightsChanged = lightDataContainer.getNumberOfLightsChanged();

		for (auto const & lightDataMapEntry : lightDataMap) {
			LightData const & lightData = lightDataMapEntry.second;
			if (numberOfLightsChanged || lightData.changed) {
				SpString const indexStr = std::to_string(index);
				SpString const variableAccessPrefix = "lightArray[" + indexStr + "]";
				shaderProgram.setInt(variableAccessPrefix + ".lightType", (int)lightData.type);
				shaderProgram.setVec3(variableAccessPrefix + ".color",
					lightData.color.x, lightData.color.y, lightData.color.z);
				shaderProgram.setVec3(variableAccessPrefix + ".position",
					lightData.position.x, lightData.position.y, lightData.position.z);
				shaderProgram.setVec3(variableAccessPrefix + ".direction",
					lightData.direction.x, lightData.direction.y, lightData.direction.z);
			}

			++index;
		}

		int const numberOfLights = lightDataMap.size();
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

			renderData.shaderProgram.use();

			updateLights(renderData.shaderProgram);

			if (renderData.modelMatrixChanged) {
				Matrix4x4 const modelMatrix = renderData.GetModelMatrix();
				SpString const & modelMatrixUniformName = "modelMatrix";
				renderData.shaderProgram.setMatrix4fv(modelMatrixUniformName, modelMatrix.getValuePtr());
			}

			if (cameraDataChanged) {
				updateCamera(renderData.shaderProgram, viewMatrix, projectionMatrix, cameraPos, cameraRotation);
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
