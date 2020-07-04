#include "Render/TextureManager.h"

#include <map>

#include "PlatformIndependence/SpHash.h"
#include "PlatformIndependence/SpString.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	TextureManager TextureManager::instance;

	TextureManager & TextureManager::getInstance() {
		return TextureManager::instance;
	}

	Texture const TextureManager::getTexture(SpString const & texturePath, bool const genMipMap, GLenum const format) {
		auto textureMapEnd = this->_textureMap.cend();
		SpHashValue pathHashValue = calculateHashValue(texturePath);

		for (auto textureMapIter = this->_textureMap.cbegin(); textureMapIter != textureMapEnd; ++textureMapIter) {
			Texture const & texture = textureMapIter->second;

			if (texture.getPathHashValue() == pathHashValue &&
				texture.getGenMipMap() == genMipMap &&
				texture.getFormat() == format) {
				return texture;
			}
		}

		Texture texture{ texturePath, genMipMap, format };
		SpUnsigned id = texture.getId();
		this->_textureMap.insert(std::pair<SpUnsigned, Texture const>{ id, texture });

		return texture;
	}

	Texture const TextureManager::getTexture(SpInt textureId) {
		return this->_textureMap.at(textureId);
	}
}
