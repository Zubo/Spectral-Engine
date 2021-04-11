#pragma once

#include <iostream>

#include <glad/glad.h>
#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <PlatformIndependence/SpHash.hpp>

namespace sp {
	class Texture {
	public:
		Texture(SpString const & path, bool const genMipmap, GLenum format);

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

		inline SpInt getWidth() const {
			return _width;
		}

		inline SpInt getHeight() const {
			return _height;
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
