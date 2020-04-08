#pragma once

#include "glad/glad.h"

#include "Core/Math/Matrix4x4.h"
#include "Render/Shader/ShaderProgram.h"

namespace sp {
	class Font;
	class Vector2;

	class TextRenderer {
	public:
		static TextRenderer & getInstance();
	private:
		static TextRenderer instance;

	public:
		void init();
		void renderText(
			SpString const & text,
			Font const & font,
			ShaderProgram const & shaderProgram,
			Vector2 const & position,
			Vector2 const & scale) const;

	private:
		Matrix4x4 getOrthoProjectionMatrix() const;

	private:
		GLuint VBO;
		GLuint VAO;
	};
}
