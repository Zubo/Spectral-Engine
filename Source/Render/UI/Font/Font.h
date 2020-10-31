#pragma once

#include <map>
#include <memory>

#include "PlatformIndependence/SpString.h"
#include "Render/UI/Font/Character.h"

namespace sp {
	class Font {
	public:
		static std::unique_ptr<Font const> getFont(SpString const & path);

	public:
		void insertCharacter(unsigned char key, Character const & character);
		Character const getCharacter(unsigned char const c) const;

	private:
		Font() = default;

	private:
		std::map<unsigned char, Character const> characterMap;
	};
}
