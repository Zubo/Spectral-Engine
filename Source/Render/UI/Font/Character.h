#pragma once

#include "Core/Math/Vector2.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class Character {
	public:
		Character(
			SpUnsigned const textureId,
			SpUnsigned const width,
			SpUnsigned const height,
			SpUnsigned const bitmapLeft,
			SpUnsigned const bitmapTop,
			SpUnsigned const advance);

	public:
		SpUnsigned const textureId;
		SpUnsigned const width;
		SpUnsigned const height;
		SpUnsigned const bitmapLeft;
		SpUnsigned const bitmapTop;
		SpUnsigned const advance;
	};
}
