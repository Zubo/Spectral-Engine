#pragma once

#include <memory>

#include "glad/glad.h"

#include "Core/Math/Matrix4x4.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/UI/Font/Font.h"

namespace sp {
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
			Vector2 const & position,
			Vector2 const & scale) const;

	private:
		Matrix4x4 getOrthoProjectionMatrix() const;

	private:
		GLuint VBO;
		GLuint VAO;
		std::shared_ptr<Font const> font;
		ShaderProgram shaderProgram;
	};
}
