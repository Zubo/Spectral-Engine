#include "Render/UI/Font/Font.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "ft2build.h"
#include FT_FREETYPE_H
#include "Render/UI/Font/Character.h"
#include "Render/UI/Font/FreeTypeHelper.h"

std::shared_ptr<sp::Font const> const sp::Font::getFont(SpString const & path) {
	FT_Face face;
	if (createFace(path, face)) {
		return nullptr;
	}

	std::shared_ptr<Font> font = std::shared_ptr<Font>(new Font);
	loadFontCharacters(*font, face);

	return font;
}

void sp::Font::insertCharacter(unsigned char key, Character const & character) {
	std::pair<unsigned char, Character const> const pair{ key, character };
	characterMap.insert(pair);
}

sp::Character const sp::Font::getCharacter(unsigned char const c) const {
	return characterMap.at(c);
}
