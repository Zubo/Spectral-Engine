#include "Render/TextRenderer.h"

#include "Core/Math/LinearTransformations.h"
#include "Core/Utility/ResourcesPathProvider.h"
#include "glad/glad.h"
#include "PlatformIndependence/SpType.h"
#include "PlatformIndependence/SpWindow.h"
#include "Render/UI/Font/Character.h"
#include "Render/UI/Font/Font.h"

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
		constexpr SpInt quadSize = 6 * 4 * sizeof(float);	// Quad has 2 triangles, each with 3 xy vertices
		glBufferData(GL_ARRAY_BUFFER, quadSize, NULL, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		SpString const fontPath{ ResourcesPathProvider::getResourcesDirectoryPath() + SpString{ "/Fonts/Arial.ttf" } };
		this->font = Font::getFont(fontPath);

		SpString const vertexShaderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{"/vertex_text_shader.glsl" } };
		SpString const fragmentShaderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{"/fragment_text_shader.glsl" } };
		this->shaderProgram = ShaderProgram{ vertexShaderPath, fragmentShaderPath };
	}

	void TextRenderer::renderText(
		SpString const & text,
		Vector2 const & position,
		Vector2 const & scale
	) const {
		Matrix4x4 const orthoProjectionMatrix = this->getOrthoProjectionMatrix();

		this->shaderProgram.use();
		shaderProgram.setMatrix4fv("projection", orthoProjectionMatrix.getValuePtr());
		shaderProgram.setInt("textu", 0);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(this->VAO);

		SpFloat characterOffsetX = 0.0f;

		for (SpString::const_iterator charIterator = text.begin(); charIterator != text.end(); ++charIterator) {
			Character const character = this->font->getCharacter(*charIterator);
			Vector2 const currentCharPos = position + Vector2{ characterOffsetX, 0.0F };
			Vector2 const characterBearing{ (float)character.bitmapLeft, (float)character.bitmapTop };
			Vector2 const textureOrigin = currentCharPos + characterBearing;

			SpFloat const scaleX = scale.x;
			SpFloat const scaleY = scale.y;

			SpFloat const characterVertices[6][4]{
				{ textureOrigin.x * scaleX, textureOrigin.y * scaleY, 0.0F, 0.0F },
				{ (textureOrigin.x + character.width) * scaleX, textureOrigin.y * scaleY, 1.0F, 0.0F },
				{ textureOrigin.x * scaleX, (textureOrigin.y - character.height) * scaleY, 0.0F, 1.0F },
				{ textureOrigin.x * scaleX, (textureOrigin.y - character.height) * scaleY, 0.0F, 1.0F },
				{ (textureOrigin.x + character.width) * scaleX, (textureOrigin.y - character.height) * scaleY, 1.0F, 1.0F },
				{ (textureOrigin.x + character.width) * scaleX, textureOrigin.y * scaleY, 1.0F, 0.0F }
			};

			glBindTexture(GL_TEXTURE_2D, character.textureId);
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
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

	Matrix4x4 TextRenderer::getOrthoProjectionMatrix() const {
		SpWindow const * const window = SpWindow::getInstance();
		SpInt const width = window->getWidht();
		SpInt const height = window->getHeight();
		return getOrthographicMat(0, width, 0, height);
	}
}
