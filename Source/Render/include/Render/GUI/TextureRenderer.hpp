#pragma once

#include <glad/glad.h>
#include <Core/Math/Vector2.hpp>
#include <Render/Texture.hpp>
#include <Render/Shader/ShaderProgram.hpp>

namespace sp {
	class RenderContext;

	class TextureRenderer {
	public:
		static void init();
		static void render(
			RenderContext const & renderContext, 
			Texture const texture, 
			Vector2 const position, 
			Vector2 const size);

	private:
		static GLuint _VAO;
		static GLuint _VBO;
		static ShaderProgram _shaderProgram;
	};
}