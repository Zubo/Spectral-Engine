#include <Render/GUI/Elements/GUIButton.hpp>
#include <Render/GUI/Elements/Settings/GUIButtonSettings.hpp>
#include <Render/RenderContext.hpp>
#include <Render/GUI/GUIDrawCallDataContainer.hpp>
#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>
#include <Render/GUI/DrawCallData/TextureDrawCallData.hpp>

namespace sp{
	bool guiButton(RenderContext & renderContext, Vector2 const position, Vector2 const size, GUIButtonSettings const & guiButtonParams) {
		GUIDrawCallDataContainer & guiDrawCallDataContainer{ renderContext.getGUIDrawCallDataContainer() };
		guiDrawCallDataContainer.enqueueDrawCallData(TextureDrawCallData {
			guiButtonParams.BackgroundTexture,
			position,
			size
		});
		
		guiDrawCallDataContainer.enqueueDrawCallData(TextDrawCallData {
			guiButtonParams.ButtonText,
			position + size / 2,
			Vector2::getVectorOne(),
			{ *guiButtonParams.ButtonTextRenderSettings.FontRef, guiButtonParams.ButtonTextRenderSettings.FontSize }
		});

		return false;
	}
}
