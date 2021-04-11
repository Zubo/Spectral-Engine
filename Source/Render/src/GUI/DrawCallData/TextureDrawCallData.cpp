#include <Render/GUI/DrawCallData/TextureDrawCallData.hpp>
#include <Render/GUI/TextureRenderer.hpp>

namespace sp {
	TextureDrawCallData::TextureDrawCallData(Texture const texture, Vector2 const position, Vector2 const scale) :
		Tex{ texture },
		Position{ position },
		Scale{ scale } {
	}
	
	void TextureDrawCallData::render(RenderContext const & renderContext) const {
		TextureRenderer::render(renderContext, Tex, Position, Scale);
	}
}
