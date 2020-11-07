#pragma once

#include <memory>

#include "glad/glad.h"

#include "Core/Math/Matrix4x4.h"
#include "Core/Utility/OptionalRef.h"
#include "PlatformIndependence/SpType.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/UI/Font/Font.h"

namespace sp {
	class Vector2;
	class SpWindow;

	class TextRenderer {
	public:
		static void init();
		static void renderText(
			SpWindow const & window,
			SpString const & text,
			Vector2 const & position,
			Vector2 const & scale);

	private:
		static Matrix4x4 getOrthoProjectionMatrix(SpWindow const & spWindow);

	private:
		static GLuint _VBO;
		static GLuint _VAO;
		static std::unique_ptr<Font const> _font;
		static ShaderProgram _shaderProgram;
	};
}
