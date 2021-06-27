#pragma once

#include <Core/Utility/OptionalRef.hpp>
#include <Core/Utility/ResourcesPathProvider.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/Texture.hpp>
#include <Render/TextureManager.hpp>
#include <Render/GUI/Font/Font.hpp>
#include <Render/GUI/Settings/TextRenderSettings.hpp>

namespace sp {
	struct GUIButtonSettings {
		Texture BackgroundTexture{ TextureManager::getInstance().getTexture(ResourcesPathProvider::getFullResourcePath(DefaultTexturePath), true, GL_RGBA) };
		SpString ButtonText{ "Button Text" };
		TextRenderSettings ButtonTextRenderSettings;

	private:
		static constexpr char const * DefaultTexturePath = "Art/container.png";
	};
}
