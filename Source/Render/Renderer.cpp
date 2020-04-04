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

	inline void updateLights(ShaderProgram const & shaderProgram) {
		LightDataContainer const & lightDataContainer = LightDataContainer::getInstance();

		if (lightDataContainer.getNumberOfLightsChanged()) {
			// update all lights
		}
		else {
			// update only lights that have changed flag on
		}
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

			if (renderData.modelMatrixChanged) {
				Matrix4x4 const modelMatrix = renderData.GetModelMatrix();
				SpString const & modelMatrixUniformName = "modelMatrix";
				renderData.shaderProgram.setMatrix4fv(modelMatrixUniformName, modelMatrix.getValuePtr());
			}

			if (cameraDataChanged) {
				updateCamera(renderData.shaderProgram, viewMatrix, projectionMatrix, cameraPos, cameraRotation);
			}

			glBindVertexArray(renderData.VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		renderDataContainer.resetAllModelMatrixUpdated();
		LightDataContainer & lightDataContainer = LightDataContainer::getInstance();
		lightDataContainer.setNumberOfLightsChangedToFalse();
		lightDataContainer.setAllLightDataChangedToFalse();
		CameraData::setDataChangedToFalse();
	}
}
