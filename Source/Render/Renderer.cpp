#include "Render/Renderer.h"

#include "glad/glad.h"
#include "Render/RenderData.h"
#include "RenderDataContainer.h"

namespace sp {
	void renderAll() {
		RenderDataContainer const & renderDataContainer = RenderDataContainer::GetInstance();

		auto iterator = renderDataContainer.getRenderDataMap().cbegin();
		auto end = renderDataContainer.getRenderDataMap().cend();
		
		for (iterator; iterator != end; ++iterator) {
			RenderData const & renderData = iterator->second;
			glBindVertexArray(renderData.VAO);
			glDrawArrays(GL_TRIANGLES, 0, renderData.elementCount);
		}

	}
}
