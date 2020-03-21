#include "Render/Renderer.h"

#include "Core/Math/Direction.h"
#include "glad/glad.h"
#include "Render/CameraData.h"
#include "Render/RenderData.h"
#include "RenderDataContainer.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	class Matrix4x4;
	class Vector3;

	void renderAll() {
		RenderDataContainer & renderDataContainer = RenderDataContainer::GetInstance();

		auto iterator = renderDataContainer.getRenderDataMap().cbegin();
		auto end = renderDataContainer.getRenderDataMap().cend();
		
		Matrix4x4 const & projectionMatrix = CameraData::GetProjectionMatrix();
		Matrix4x4 const & viewMatrix = CameraData::GetViewMatrix();
		Vector3 const & cameraPos = CameraData::getTranslation();
		bool const cameraDataChanged = CameraData::getDataChanged();

		for (iterator; iterator != end; ++iterator) {
			RenderData const & renderData = iterator->second;

			if (renderData.modelMatrixChanged) {
				Matrix4x4 const modelMatrix = renderData.GetModelMatrix();
				SpString const & modelMatrixUniformName = "mvpMatrix";
					renderData.shaderProgram.setMatrix4fv(modelMatrixUniformName, modelMatrix.getValuePtr());
			}

			if (cameraDataChanged)
			{
				SpString const & projectionMatrixUniformName = "projectionMatrix";
				renderData.shaderProgram.setMatrix4fv(projectionMatrixUniformName, projectionMatrix.getValuePtr());

				SpString const & viewMatrixUniformName = "viewMatrix";
				renderData.shaderProgram.setMatrix4fv(viewMatrixUniformName, viewMatrix.getValuePtr());

				SpString const & cameraPositionUniformName = "cameraPos";
				renderData.shaderProgram.setVec3(cameraPositionUniformName, cameraPos.x, cameraPos.y, cameraPos.z);

				SpString const & cameraDirectionUniformName = "cameraDir";
				Vector3 const cameraRotation = CameraData::getRotation();
				Vector3 const cameraDirection = getDirection(cameraRotation.x, cameraRotation.y);
				renderData.shaderProgram.setVec3(cameraDirectionUniformName, cameraDirection.x, cameraDirection.y, cameraDirection.z);
			}

			glBindVertexArray(renderData.VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		renderDataContainer.resetAllModelMatrixUpdated();
	}
}
