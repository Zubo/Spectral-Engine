#pragma once

#include <memory>

#include <glad/glad.h>

#include <Core/Math/Matrix4x4.hpp>
#include <Core/Utility/OptionalRef.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/Shader/ShaderProgram.hpp>
#include <Render/GUI/Font/Font.hpp>

namespace sp {
	class Vector2;
	class SpWindow;
	class RenderContext;

	class TextRenderer {
	public:
		static void init();
		static void renderText(
			RenderContext const & renderContext,
			SpString const & text,
			Vector2 const & position,
			Vector2 const & scale,
			Font const & font);

	private:
		static Matrix4x4 getOrthoProjectionMatrix(SpWindow const & spWindow);

	private:
		static GLuint _VBO;
		static GLuint _VAO;
		static ShaderProgram _shaderProgram;
	};
}
