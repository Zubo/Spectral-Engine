#pragma once

#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#define DEFAULT_FONT_SIZE 48

namespace sp {
	class Font;

	SpInt createFace(SpString const & path, FT_Face & face);
	void loadFontCharacters(Font & font, FT_Face const & face);
}
