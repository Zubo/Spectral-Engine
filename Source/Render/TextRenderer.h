#pragma once

#include <memory>

#include "glad/glad.h"

#include "Core/Math/Matrix4x4.h"
#include "PlatformIndependence/SpType.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/UI/Font/Font.h"

namespace sp {
	class Vector2;
	class SpWindow;

	class TextRenderer {
	public:
		TextRenderer(SpWindow const & spWindow);

	public:
		void init();
		void renderText(
			SpString const & text,
			Vector2 const & position,
			Vector2 const & scale) const;

	private:
		Matrix4x4 getOrthoProjectionMatrix() const;

	private:
		GLuint _VBO;
		GLuint _VAO;
		std::unique_ptr<Font const> _font;
		ShaderProgram _shaderProgram;
		SpWindow const & _spWindow;
	};
}
