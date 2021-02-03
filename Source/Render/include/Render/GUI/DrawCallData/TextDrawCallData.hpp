#pragma once

#include <Core/Math/Vector2.hpp>
#include <Core/Utility/OptionalRef.hpp>
#include <PlatformIndependence/SpString.hpp>

namespace sp{
	class Font;

	class TextDrawCallData {
	public:
		TextDrawCallData(
			SpString const & text,
			Vector2 const position,
			Vector2 const scale,
			Font const & font);

	public:
		SpString Text;
		Vector2 Position;
		Vector2 Scale;
		OptionalRef<Font const> FontRef;
	};
}
