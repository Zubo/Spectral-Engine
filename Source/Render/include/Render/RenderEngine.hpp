#pragma once

#include <memory>
#include <vector>

#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class RenderContext;

	class RenderEngine {
	public:
		RenderEngine() = default;
		RenderEngine(RenderEngine const & renderEngine) = delete;

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