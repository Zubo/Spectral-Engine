#include "Render/RenderContext.h"
#include "Render/RenderEngine.h"
#include "Render/RenderFunctions.h"

namespace sp {
	SpInt RenderEngine::_nextRenderContextId{ 0 };


	RenderContext & RenderEngine::createContext(bool const isMainContext) {
		std::unique_ptr<RenderContext> contextUnique{ std::make_unique<RenderContext>(_nextRenderContextId++) };

		RenderContext & contextRef = *contextUnique;

		_renderContexts.push_back(std::move(contextUnique));

		if (isMainContext) {
			_mainContextId = contextRef.Id;
		}

		return contextRef;
	}

	bool RenderEngine::renderAllContexts() {
		for (auto && renderContext : _renderContexts) {
			if (renderContext->Id == _mainContextId) {
				std::unique_ptr<SpWindow> const & contextWindowUnique = renderContext->getWindow();

				if (contextWindowUnique != nullptr && glfwWindowShouldClose(contextWindowUnique->getConcreteWindow())) {
					return false;
				}
			}

			render(*renderContext);
		}

		return true;
	}
}
