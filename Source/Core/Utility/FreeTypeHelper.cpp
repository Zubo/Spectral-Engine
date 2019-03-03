#include <iostream>

#include "glad/glad.h"
#include "UI/Font/Character.h"
#include "UI/Font/Font.h"
#include "Utility/FreeTypeHelper.h"

int sp::createFace(std::string const & path, FT_Face & face) {
	FT_Library freeType;
	if (FT_Init_FreeType(&freeType)) {
		std::cout << "Error: Could not init FreeType library" << std::endl;
		return -1;
	}

	if (FT_New_Face(freeType, path.c_str(), 0, &face)) {
		std::cout << "Error: Could not load font" << std::endl;
		return -1;
	}

	FT_Set_Pixel_Sizes(face, 0, DEFAULT_FONT_SIZE);
}

void sp::loadFontCharacters(Font & font, FT_Face const & face) {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (unsigned char c = 0; c < 128; ++c) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "Error: Failed to load glyph: " << (int)c << std::endl;
		}

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		FT_GlyphSlot const & glyph = face->glyph;

		Character character{
			texture,
			glyph->bitmap.width,
			glyph->bitmap.rows,
			(unsigned int)glyph->bitmap_left,
			(unsigned int)glyph->bitmap_top,
			(unsigned int)glyph->advance.x
		};

		font.insertCharacter(c, character);
	}
}