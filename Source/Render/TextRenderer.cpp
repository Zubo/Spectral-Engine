#include "Render/TextRenderer.h"

#include "Core/Math/LinearTransformations.h"
#include "glad/glad.h"
#include "PlatformIndependence/SpWindow.h"

namespace sp {
	TextRenderer TextRenderer::instance;

	TextRenderer & TextRenderer::getInstance() {
		return TextRenderer::instance;
	}

	void TextRenderer::init() {
		glGenVertexArrays(1, &this->VAO);
		glBindVertexArray(this->VAO);

		glGenBuffers(1, &this->VBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		constexpr int quadSize = 6 * 2 * sizeof(float);	// Quad has 2 triangles, each with 3 xy vertices
		glBufferData(GL_ARRAY_BUFFER, quadSize, NULL, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 2 * sizeof(float), GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void TextRenderer::renderText(
		SpString const & text,
		Font const & font,
		ShaderProgram const & shaderProgram,
		Vector2 const & position
	) {
		Matrix4x4 const orthoProjectionMatrix = this->getOrthoProjectionMatrix();

		shaderProgram.use();
		shaderProgram.setMatrix4fv("projection", orthoProjectionMatrix.getValuePtr());
		shaderProgram.setInt("textu", 0);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(this->VAO);

		// TODO: iterate through characters and draw them
	}

	Matrix4x4 TextRenderer::getOrthoProjectionMatrix() const {
		SpWindow const * const window = SpWindow::getInstance();
		int const width = window->getWidht();
		int const height = window->getHeight();
		return getOrthographicMat(0, width, 0, height);
	}
}
