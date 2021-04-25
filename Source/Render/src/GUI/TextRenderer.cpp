#include <Core/Math/LinearTransformations.hpp>
#include <Core/Math/Vector3.hpp>
#include <Core/Utility/ResourcesPathProvider.hpp>
#include <glad/glad.h>
#include <PlatformIndependence/SpType.hpp>
#include <PlatformIndependence/SpWindow.hpp>
#include <Render/RenderContext.hpp>
#include <Render/GUI/TextRenderer.hpp>
#include <Render/GUI/Font/Character.hpp>
#include <Render/GUI/Font/Font.hpp>

namespace sp {
	 GLuint TextRenderer::_VBO;
	 GLuint TextRenderer::_VAO;
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
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		SpString const vertexShaderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{"/vertex_text_shader.glsl" } };
		SpString const fragmentShaderPath{ ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{"/fragment_text_shader.glsl" } };
		_shaderProgram = ShaderProgram{ vertexShaderPath, fragmentShaderPath };
	}

	void TextRenderer::renderText(
		RenderContext const & renderContext,
		SpString const & text,
		Vector2 const & position,
		Vector2 const & scale,
		Font const & font) {
		std::unique_ptr<SpWindow> const & spWindow = renderContext.getWindow();

		if (spWindow == nullptr) {
			return;
		}

		spWindow->makeCurrentContext();

		SpInt const windowWidth = spWindow->getWidht();
		SpInt const windowHeight = spWindow->getHeight();
		Matrix4x4 const orthoProjectionMatrix = getOrthographicMat(0.0F, static_cast<SpFloat>(windowWidth), 0.0F, static_cast<SpFloat>(windowHeight));

		Matrix4x4 modelMatrix;
		modelMatrix = translate(modelMatrix, Vector3{ position });

		Matrix4x4 const mvpMatrix = orthoProjectionMatrix * modelMatrix;

		_shaderProgram.use();
		_shaderProgram.setMatrix4fv("mvpMatrix", mvpMatrix.getValuePtr());
		_shaderProgram.setInt("text0", 0);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(_VAO);

		SpFloat characterOffsetX = 0.0f;

		for (const char charIterator : text) {
			Character const character = font.getCharacter(charIterator);
			Vector2 const currentCharPos = Vector2{ characterOffsetX, 0.0F };
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
}
