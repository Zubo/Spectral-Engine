#include "Render/UI/Font/Font.h"

#include <iostream>

#include "ft2build.h"
#include FT_FREETYPE_H
#include "Render/UI/Font/Character.h"
#include "Render/UI/Font/FreeTypeHelper.h"

namespace sp {
	std::unique_ptr<Font const> Font::getFont(SpString const & path) {
		FT_Face face;
		if (createFace(path, face)) {
			return nullptr;
		}

		std::unique_ptr<Font> font{ new Font() };
		loadFontCharacters(*font, face);

		return std::move(font);
	}

	void Font::insertCharacter(unsigned char key, Character const & character) {
		std::pair<unsigned char, Character const> const pair{ key, character };
		characterMap.insert(pair);
	}

	Character const Font::getCharacter(unsigned char const c) const {
		return characterMap.at(c);
	}
}
