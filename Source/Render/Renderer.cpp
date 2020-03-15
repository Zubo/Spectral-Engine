#include "Render/Renderer.h"

#include "glad/glad.h"
#include "Render/RenderData.h"
#include "RenderDataContainer.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	void renderAll() {
		RenderDataContainer const & renderDataContainer = RenderDataContainer::GetInstance();

		auto iterator = renderDataContainer.getRenderDataMap().cbegin();
		auto end = renderDataContainer.getRenderDataMap().cend();
		
		for (iterator; iterator != end; ++iterator) {
			RenderData const & renderData = iterator->second;

			if (renderData.modelMatrixChanged) {
				Matrix4x4 const modelMatrix = renderData.GetModelMatrix();
				SpString const & modelMatrixUniformName = "mvpMatrix";
					renderData.shaderProgram.setMatrix4fv(modelMatrixUniformName, modelMatrix.getValuePtr());
			}

			glBindVertexArray(renderData.VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
	}
}
