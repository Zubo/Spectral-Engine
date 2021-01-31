#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utility/OptionalRef.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/UI/Font/Character.hpp>

namespace sp {
	class Font {
	public:
		static OptionalRef<Font const> getFont(SpString const & path);

	private:
		static std::unordered_map< SpString, std::unique_ptr<Font> > fontMap;

	public:
		void insertCharacter(unsigned char key, Character const & character);
		Character const getCharacter(unsigned char const c) const;

	private:
		Font() = default;

	private:
		std::unordered_map<unsigned char, Character const> _characterMap;
	};
}
