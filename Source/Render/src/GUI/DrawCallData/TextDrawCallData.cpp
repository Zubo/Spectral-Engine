#include <Core/Utility/OptionalRef.hpp>
#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>
#include <Render/GUI/TextRenderer.hpp>
#include <Render/RenderContext.hpp>

namespace sp {	
	void TextDrawCallData::render(RenderContext const & renderContext) const {
		TextRenderer::renderText(renderContext, Text, Position, Scale, Settings.FontRef, Settings.FontSize);
	}
}
