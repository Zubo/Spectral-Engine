#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "PlatformIndependence/SpHash.h"


namespace sp {
	Texture::Texture(SpString const & path, bool const genMipMap, GLenum format) :
			_genMipMap{ genMipMap }, _format{ format }, _pathHashValue{ calculateHashValue(path) } {
		glGenTextures(1, &this->_id);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->_id);

		unsigned char * data = stbi_load(path.c_str(), &this->_width, &this->_height, &this->_nrChannel, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->_width, this->_height, 0, format, GL_UNSIGNED_BYTE, data);

			if (this->_genMipMap) {
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}
		else {
			std::cout << "Error loading texture file: " << path << std::endl;
		}

		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
	}

	Texture::~Texture() {
	}
}
