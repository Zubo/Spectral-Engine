#pragma once

#include <map>

#include "glad/glad.h"
#include "Render/Texture.h"
#include "PlatformIndependence/SpString.h"

namespace sp {
	class TextureManager {
	public:
		static TextureManager & getInstance();

	private:
		static TextureManager instance;

	public:
		Texture const getTexture(SpString const & texturePath, bool const genMipMap, GLenum const format);
		Texture const getTexture(int textureId);

	private:
		TextureManager() = default;
		TextureManager(TextureManager const & textureManager) = delete;
		TextureManager operator=(TextureManager const & textureManager) = delete;

	private:
		std::map<unsigned int, Texture const> textureMap;
	};
}
