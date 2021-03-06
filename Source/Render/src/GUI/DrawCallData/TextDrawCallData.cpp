#include <Core/Utility/OptionalRef.hpp>
#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>
#include <Render/GUI/TextRenderer.hpp>
#include <Render/RenderContext.hpp>

namespace sp {
	TextDrawCallData::TextDrawCallData(SpString const & text, Vector2 const position, Vector2 const scale, Font const & font) : 
		Text{ text },
		Position{ position },
		Scale{ scale },
		FontRef{ font } {
	}
	
	void TextDrawCallData::render(RenderContext const & renderContext) const {
		TextRenderer::renderText(renderContext, Text, Position, Scale, FontRef);
	}
}
