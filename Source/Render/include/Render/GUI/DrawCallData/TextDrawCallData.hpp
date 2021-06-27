#pragma once

#include <Core/Math/Vector2.hpp>
#include <Core/Utility/OptionalRef.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/GUI/Settings/TextRenderSettings.hpp>

namespace sp{
	class RenderContext;

	struct TextDrawCallData {
	public:
		void render(RenderContext const & renderContext) const;

	public:
		SpString Text;
		Vector2 Position;
		Vector2 Scale;
		TextRenderSettings Settings;
	};
}
