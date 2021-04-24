#pragma once

#include <PlatformIndependence/SpString.hpp>

namespace sp {
	class RenderContext;
	struct GUIButtonSettings;

	bool guiButton(RenderContext & renderContext, GUIButtonSettings const & guiButtonParams);
}
