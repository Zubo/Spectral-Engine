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
			return _id;
		}

		inline SpHashValue const getPathHashValue() const {
			return _pathHashValue;
		}

		inline bool const getGenMipMap() const {
			return _genMipMap;
		}

		inline GLenum const getFormat() const {
			return _format;
		}

	private:
		SpUnsigned _id;
		SpInt _width;
		SpInt _height;
		SpInt _nrChannel;
		bool _genMipMap;
		GLenum _format;
		SpHashValue _pathHashValue;
	};
}
