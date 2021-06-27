#pragma once

#include <Core/Math/Vector2.hpp>
#include <Core/Utility/OptionalRef.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/Texture.hpp>
#include <Render/GUI/Font/Font.hpp>

namespace sp {
	struct GUIButtonSettings {
		GUIButtonSettings(Vector2 position, Vector2 size, SpString const & buttonText);

		Vector2 Position;
		Vector2 Size;
		Texture BackgroundTexture;
		OptionalRef<Font const> ButtonTextFontOptionalRef;
		SpString ButtonText;
		SpInt ButtonTextFontSize = DefaultFontSize;

	private:
		static constexpr char const * DefaultTexturePath = "Art/container.png";
		static constexpr char const * DefaultFontPath = "Fonts/Arial.ttf";
		static constexpr SpInt DefaultFontSize = 11;
	};
}
