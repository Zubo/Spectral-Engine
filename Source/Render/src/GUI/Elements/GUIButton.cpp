#include <Render/GUI/Elements/GUIButton.hpp>
#include <Render/GUI/Elements/Settings/GUIButtonSettings.hpp>
#include <Render/RenderContext.hpp>
#include <Render/GUI/GUIDrawCallDataContainer.hpp>
#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>
#include <Render/GUI/DrawCallData/TextureDrawCallData.hpp>

namespace sp{
	bool guiButton(RenderContext & renderContext, GUIButtonSettings const & guiButtonParams) {
		GUIDrawCallDataContainer & guiDrawCallDataContainer{ renderContext.getGUIDrawCallDataContainer() };
		guiDrawCallDataContainer.enqueueDrawCallData(TextureDrawCallData {
			guiButtonParams.BackgroundTexture,
			guiButtonParams.Position,
			guiButtonParams.Size
		});
		
		guiDrawCallDataContainer.enqueueDrawCallData(TextDrawCallData {
			guiButtonParams.ButtonText,
			guiButtonParams.Position,
			Vector2::getVectorOne(),
			*guiButtonParams.ButtonTextFontOptionalRef
		});

		return false;
	}
}
