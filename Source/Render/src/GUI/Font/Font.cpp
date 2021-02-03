#include <Render/GUI/Font/Font.hpp>

#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H
#include <Render/GUI/Font/Character.hpp>
#include <Render/GUI/Font/FreeTypeHelper.hpp>

namespace sp {
	OptionalRef<Font const> Font::getFont(SpString const & path) {
		FT_Face face;
		if (createFace(path, face)) {
			return OptionalRef<Font const>{};
		}

		auto existingFontIter = fontMap.find(path);
		if (existingFontIter != fontMap.end()) {
			return OptionalRef<Font const>{ *existingFontIter->second };
		}

		auto newFontPair = fontMap.emplace(path, std::unique_ptr<Font>{ new Font() });
		Font & newFont = *newFontPair.first->second;
		loadFontCharacters(newFont, face);

		return OptionalRef<Font const>{ newFont };
	}

	std::unordered_map< SpString, std::unique_ptr<Font> > Font::fontMap;

	void Font::insertCharacter(unsigned char key, Character const & character) {
		std::pair<unsigned char, Character const> const pair{ key, character };
		_characterMap.insert(pair);
	}

	Character const Font::getCharacter(unsigned char const c) const {
		return _characterMap.at(c);
	}
}
