#pragma once

#include <unordered_map>

#include <glad/glad.h>
#include <Render/Texture.h>
#include <PlatformIndependence/SpString.h>

namespace sp {
	class TextureManager {
	public:
		static TextureManager & getInstance();

	private:
		static TextureManager _instance;

	public:
		Texture const getTexture(SpString const & texturePath, bool const genMipMap, GLenum const format);
		Texture const getTexture(SpInt textureId);

	private:
		TextureManager() = default;
		TextureManager(TextureManager const & textureManager) = delete;
		TextureManager operator=(TextureManager const & textureManager) = delete;

	private:
		std::unordered_map<SpUnsigned, Texture const> _textureMap;
	};
}
