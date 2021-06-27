#include <Render/GUI/DrawCallData/TextureDrawCallData.hpp>
#include <Render/GUI/TextureRenderer.hpp>

namespace sp {	
	void TextureDrawCallData::render(RenderContext const & renderContext) const {
		TextureRenderer::render(renderContext, Tex, Position, Scale);
	}
}
