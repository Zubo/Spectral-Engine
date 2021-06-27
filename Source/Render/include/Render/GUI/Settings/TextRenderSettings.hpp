#pragma once

#include <Core/Utility/OptionalRef.hpp>
#include <Core/Utility/ResourcesPathProvider.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/GUI/Font/Font.hpp>

namespace sp {
	struct TextRenderSettings {
		OptionalRef<Font const> FontRef{ Font::getFont(ResourcesPathProvider::getFullResourcePath(DefaultFontPath)) };
		SpInt FontSize = 11;

		static constexpr char const * DefaultFontPath = "Fonts/Arial.ttf";
		static constexpr SpInt DefaultFontSize = 11;
	};
}