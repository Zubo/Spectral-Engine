#include "TextRenderer.h"
#include "TextRenderer.h"
#include "Render/TextRenderer.h"

#include "Core/Math/LinearTransformations.h"
#include "Core/Utility/ResourcesPathProvider.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "PlatformIndependence/SpType.h"
#include "PlatformIndependence/SpWindow.h"
#include "Render/UI/Font/Character.h"
#include "Render/UI/Font/Font.h"

namespace sp {
	 GLuint TextRenderer::_VBO;
	 GLuint TextRenderer::_VAO;
	 std::unique_ptr<Font const> TextRenderer::_font;
	 ShaderProgram TextRenderer::_shaderProgram;

	void TextRenderer::init() {
		glGenVertexArrays(1, &_VAO);
		glBindVertexArray(_VAO);

		glGenBuffers(1, &_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		constexpr SpInt quadSize = 6 * 4 * sizeof(float);	// Quad has 2 triangles, each with 3 xy vertices
		glBufferData(GL_ARRAY_BUFFER, quadSize, NULL, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		SpString const fontPath{ ResourcesPathProvider::getResourcesDirectoryPath() + SpString{ "/Fonts/Arial.ttf" } };
		_font = Font::getFont(fontPath);

		SpString const vertexShaderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{"/vertex_text_shader.glsl" } };
		SpString const fragmentShaderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{"/fragment_text_shader.glsl" } };
		_shaderProgram = ShaderProgram{ vertexShaderPath, fragmentShaderPath };
	}

	void TextRenderer::renderText(
		SpWindow const & spWindow,
		SpString const & text,
		Vector2 const & position,
		Vector2 const & scale) {
		GLFWwindow * glfwWindow = spWindow.getConcreteWindow();
		glfwMakeContextCurrent(glfwWindow);

		Matrix4x4 const orthoProjectionMatrix = getOrthoProjectionMatrix(spWindow);

		_shaderProgram.use();
		_shaderProgram.setMatrix4fv("projection", orthoProjectionMatrix.getValuePtr());
		_shaderProgram.setInt("textu", 0);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(_VAO);

		SpFloat characterOffsetX = 0.0f;

		for (SpString::const_iterator charIterator = text.begin(); charIterator != text.end(); ++charIterator) {
			Character const character = _font->getCharacter(*charIterator);
			Vector2 const currentCharPos = position + Vector2{ characterOffsetX, 0.0F };
			Vector2 const characterBearing{ (float)character.bitmapLeft, (float)character.bitmapTop };
			Vector2 const textureOrigin = currentCharPos + characterBearing;

			SpFloat const scaleX = scale.X;
			SpFloat const scaleY = scale.Y;

			SpFloat const characterVertices[6][4]{
				{ textureOrigin.X * scaleX, textureOrigin.Y * scaleY, 0.0F, 0.0F },
				{ (textureOrigin.X + character.width) * scaleX, textureOrigin.Y * scaleY, 1.0F, 0.0F },
				{ textureOrigin.X * scaleX, (textureOrigin.Y - character.height) * scaleY, 0.0F, 1.0F },
				{ textureOrigin.X * scaleX, (textureOrigin.Y - character.height) * scaleY, 0.0F, 1.0F },
				{ (textureOrigin.X + character.width) * scaleX, (textureOrigin.Y - character.height) * scaleY, 1.0F, 1.0F },
				{ (textureOrigin.X + character.width) * scaleX, textureOrigin.Y * scaleY, 1.0F, 0.0F }
			};

			glBindTexture(GL_TEXTURE_2D, character.textureId);
			glBindBuffer(GL_ARRAY_BUFFER, _VBO);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(characterVertices), characterVertices);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glDisable(GL_DEPTH_TEST);

			glDrawArrays(GL_TRIANGLES, 0, 6);

			glDisable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);

			characterOffsetX += (character.advance >> 6);
		}
	}

	Matrix4x4 TextRenderer::getOrthoProjectionMatrix(SpWindow const & spWindow) {
		SpFloat const width = static_cast<SpFloat>(spWindow.getWidht());
		SpFloat const height = static_cast<SpFloat>(spWindow.getHeight());
		return getOrthographicMat(0, width, 0, height);
	}
}
