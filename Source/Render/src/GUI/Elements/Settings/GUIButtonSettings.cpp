#include <Render/GUI/Elements/Settings/GUIButtonSettings.hpp>
#include <Render/GUI/Font/Font.hpp>
#include <Render/Texture.hpp>
#include <Core/Utility/ResourcesPathProvider.hpp>

namespace sp {
	GUIButtonSettings::GUIButtonSettings(Vector2 position, Vector2 size, SpString const & buttonText) : 
		Position{ position },
		Size{ size },
		BackgroundTexture{ ResourcesPathProvider::getFullResourcePath(DefaultTexturePath), true, GL_RGBA},
		ButtonText{ buttonText },
		ButtonTextFontOptionalRef{ Font::getFont(ResourcesPathProvider::getFullResourcePath(DefaultFontPath)) } {
	}
}
