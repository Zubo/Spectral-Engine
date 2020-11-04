#pragma once

#include <memory>
#include <vector>

#include "PlatformIndependence/SpType.h"

namespace sp {
	class RenderContext;

	class RenderEngine {
	public:
		RenderContext & createContext(bool const isMainContext);
		bool renderAllContexts();

	private:
		std::vector< std::unique_ptr<RenderContext> > _renderContexts;
		SpInt _mainContextId;

	private:
		static SpInt _nextRenderContextId;
	};
}