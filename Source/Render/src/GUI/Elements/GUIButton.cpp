#include <Core/Assert/SpAssert.hpp>
#include <Core/Math/SpMathUtils.hpp>
#include <PlatformIndependence/Input/Input.hpp>
#include <Render/GUI/Elements/GUIButton.hpp>
#include <Render/GUI/Elements/Settings/GUIButtonSettings.hpp>
#include <Render/RenderContext.hpp>
#include <Render/GUI/GUIDrawCallDataContainer.hpp>
#include <Render/GUI/DrawCallData/TextDrawCallData.hpp>
#include <Render/GUI/DrawCallData/TextureDrawCallData.hpp>

namespace sp {
	bool guiButton(RenderContext & renderContext, Vector2 const position, Vector2 const size, GUIButtonSettings const & guiButtonParams) {
		GUIDrawCallDataContainer & guiDrawCallDataContainer{ renderContext.getGUIDrawCallDataContainer() };
		guiDrawCallDataContainer.enqueueDrawCallData(TextureDrawCallData{
			guiButtonParams.BackgroundTexture,
			position,
			size
			});

		guiDrawCallDataContainer.enqueueDrawCallData(TextDrawCallData{
			guiButtonParams.ButtonText,
			position + size / 2,
			Vector2::getVectorOne(),
			{ *guiButtonParams.ButtonTextRenderSettings.FontRef, guiButtonParams.ButtonTextRenderSettings.FontSize }
			});

		std::unique_ptr<SpWindow> const & window{ renderContext.getWindow() };
		SpAssert(window != nullptr, "Assertion failed: Can't draw button on rendercontext without a window.");

		Input const & input{ window->getInput() };
		Vector2 const mousePosition{ input.getMousePosX(), input.getMousePosY() };

		// Check if already hot and click

		// else check if new hot
		bool const isHot{ isPointInBox(mousePosition, position, size) };

		if (isHot) {
			return true;
		}

		return false;
	}
}
