#pragma once

#include <PlatformIndependence/SpString.hpp>
#include <Core/Math/Vector2.hpp>

namespace sp {
	class RenderContext;
	struct GUIButtonSettings;

	bool guiButton(RenderContext & renderContext, Vector2 const position, Vector2 const size, GUIButtonSettings const & guiButtonParams);
}
