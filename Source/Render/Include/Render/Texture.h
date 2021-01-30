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

		inline SpUnsigned getId() const {
			return _id;
		}

		inline SpHashValue getPathHashValue() const {
			return _pathHashValue;
		}

		inline bool getGenMipMap() const {
			return _genMipMap;
		}

		inline GLenum getFormat() const {
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
