#pragma once

#include <memory>
#include <unordered_map>

#include <PlatformIndependence/SpString.hpp>
#include <Render/UI/Font/Character.hpp>

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
		std::unordered_map<unsigned char, Character const> characterMap;
	};
}
