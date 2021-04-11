#pragma once

#include <Core/Math/Vector2.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/Texture.hpp>

namespace sp {
	class RenderContext;

	class TextureDrawCallData {
	public:
		TextureDrawCallData(
			Texture const texture,
			Vector2 const position,
			Vector2 const scale);

	public:
		void render(RenderContext const & renderContext) const;

	public:
		Texture Tex;
		Vector2 Position;
		Vector2 Scale;
	};
}
