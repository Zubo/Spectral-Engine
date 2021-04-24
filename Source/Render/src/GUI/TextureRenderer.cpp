#include "glad/glad.h"
#include <Core/Utility/ResourcesPathProvider.hpp>
#include <Core/Math/LinearTransformations.hpp>
#include <Core/Math/Matrix4x4.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <PlatformIndependence/SpWindow.hpp>
#include <Render/BasicShapes/Quad.hpp>
#include <Render/GUI/TextureRenderer.hpp>
#include <Render/RenderContext.hpp>

namespace sp {
	GLuint TextureRenderer::_VAO{ 0 };
	GLuint TextureRenderer::_VBO{ 0 };
	ShaderProgram TextureRenderer::_shaderProgram;

	void TextureRenderer::init() {
		glGenVertexArrays(1, &_VAO);
		glBindVertexArray(_VAO);

		glGenBuffers(1, &_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(quadUV), quadUV, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, static_cast<void*>(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, reinterpret_cast<void *>(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		SpString const vertexShaderPath = ResourcesPathProvider::getFullResourcePath("Shaders/vertex_shader_texture.glsl");
		SpString const fragmentShaderPath = ResourcesPathProvider::getFullResourcePath("Shaders/fragment_shader_texture.glsl");

		_shaderProgram = ShaderProgram(vertexShaderPath, fragmentShaderPath);
		_shaderProgram.setInt("tex0", 0);
	}

	void TextureRenderer::render(RenderContext const & renderContext, Texture const texture, Vector2 const position, Vector2 const size) {
		SpWindow const & window = *renderContext.getWindow();
		Matrix4x4 modelMatrix;
		modelMatrix = performScale(modelMatrix, Vector3{ size.X, size.Y, 1.0F });
		modelMatrix = translate(modelMatrix, Vector3{ position });

		SpInt const windowWidth = window.getWidht();
		SpInt const windowHeight = window.getHeight();
		Matrix4x4 const orthographicMatrix = getOrthographicMat(0.0F, static_cast<SpFloat>(windowWidth), 0.0F, static_cast<SpFloat>(windowHeight));

		Matrix4x4 const mvpMatrix = orthographicMatrix * modelMatrix;
		_shaderProgram.setMatrix4fv("mvpMatrix", mvpMatrix.getValuePtr());

		glBindVertexArray(_VAO);

		_shaderProgram.use();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture.getId());

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glDisable(GL_BLEND);
		glBindVertexArray(0);
	}
}
