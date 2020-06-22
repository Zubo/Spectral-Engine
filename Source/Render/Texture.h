#pragma once

#include <iostream>

#include "glad/glad.h"
#include "PlatformIndependence/SpString.h"
#include "PlatformIndependence/SpType.h"
#include "PlatformIndependence/SpHash.h"

namespace sp {
	class Texture {
	public:
		Texture(SpString const & path, bool const genMipmap, GLenum format);
		~Texture();

		inline SpUnsigned const getId() const {
			return this->id;
		}

		inline SpHashValue const getPathHashValue() const {
			return this->pathHashValue;
		}

		inline bool const getGenMipMap() const {
			return this->genMipMap;
		}

		inline GLenum const getFormat() const {
			return this->format;
		}

	private:
		SpUnsigned id;
		SpInt width;
		SpInt height;
		SpInt nrChannel;
		bool genMipMap;
		GLenum format;
		SpHashValue pathHashValue;
	};
}
