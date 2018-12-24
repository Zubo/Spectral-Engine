#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

Texture::Texture(std::string const & path, bool const genMipmap, GLenum format) {
	glGenTextures(1, &this->id);
	glBindTexture(GL_TEXTURE_2D, this->id);
	
	unsigned char * data = stbi_load(path.c_str(), &this->width, &this->height, &this->nrChannel, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, format, GL_UNSIGNED_BYTE, data);

		if (genMipmap) {
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}
	else {
		std::cout << "Error loading texture file: " << path << std::endl;
	}

	stbi_image_free(data);
}

Texture::~Texture() {
}

unsigned int const Texture::getId() const {
	return this->id;
}
