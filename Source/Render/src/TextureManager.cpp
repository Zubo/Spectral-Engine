#include <Render/TextureManager.hpp>

#include <unordered_map>

#include <PlatformIndependence/SpHash.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	TextureManager TextureManager::_instance;

	TextureManager & TextureManager::getInstance() {
		return TextureManager::_instance;
	}

	Texture const TextureManager::getTexture(SpString const & texturePath, bool const genMipMap, GLenum const format) {
		auto textureMapEnd = _textureMap.cend();
		SpHashValue pathHashValue = calculateHashValue(texturePath);

		for (auto textureMapIter = _textureMap.cbegin(); textureMapIter != textureMapEnd; ++textureMapIter) {
			Texture const & texture = textureMapIter->second;

			if (texture.getPathHashValue() == pathHashValue &&
				texture.getGenMipMap() == genMipMap &&
				texture.getFormat() == format) {
				return texture;
			}
		}

		const Texture texture{ texturePath, genMipMap, format };
		const SpUnsigned id = texture.getId();
		_textureMap.insert(std::pair<SpUnsigned, Texture const>{ id, texture });

		return texture;
	}

	Texture const TextureManager::getTexture(SpInt textureId) {
		return _textureMap.at(textureId);
	}
}
