#pragma once

#include <Core/Math/Vector2.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	struct Character {
	public:
		SpUnsigned TextureId;
		SpUnsigned Width;
		SpUnsigned Height;
		SpUnsigned BitmapLeft;
		SpUnsigned BitmapTop;
		SpUnsigned Advance;
	};
}
