#include <ThirdParty/Glad/include/glad/glad.h>
#include <memory>
#include "PlatformIndependence/SpString.h"

#include "Game/Components/Transform.h"
#include "Game/Components/UI/TextRenderer.h"
#include "Game/GameObject/GameObject.h"
#include "Render/UI/Font/Character.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Utility/ResourcesPathProvider.h"
#include "Core/Math/LinearTransformations.h"


sp::TextRenderer::TextRenderer(GameObject * const gameObject) : GameObjectComponent(gameObject),
	shaderProgram{ 
		ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{ "/vertex_text_shader.glsl" },
		ResourcesPathProvider::getShaderFilesDirectoryPath() + SpString{ "/fragment_text_shader.glsl" } },
	text{ "" } {
	this->generateRenderData();
}

void sp::TextRenderer::render() const {
	Matrix4x4 const projectionMatrix = getOrthographicMat(0.0F, 800.0F, 0.0F, 600.0F);

	this->shaderProgram.use();
	this->shaderProgram.setMatrix4fv("projection", projectionMatrix.getValuePtr());
	this->shaderProgram.setVec3("TextColor", 0.9F, 0.65F, 0.13F);
	this->shaderProgram.setInt("textu", 0);
	glActiveTexture(GL_TEXTURE0);

	glBindVertexArray(this->VAO);
	Vector2 const position = this->getPosition();

	SpString::const_iterator characterIterator;
	float characterOffsetX = 0.0F;

	for (characterIterator = this->text.begin(); characterIterator != text.end(); ++characterIterator) {
		Character const character = this->font->getCharacter(*characterIterator);
		Vector2 const currentCharPos = position + Vector2{ characterOffsetX, 0.0F };
		Vector2 const characterBearing{ (float)character.bitmapLeft, (float)character.bitmapTop };
		Vector2 const textureOrigin = currentCharPos + characterBearing;
		Vector2 const scale = this->getScale();
		float const scaleX = scale.x;
		float const scaleY = scale.y;

		float const characterVertices[6][4] {
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
		glDisable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);

		characterOffsetX += (character.advance >> 6);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void sp::TextRenderer::setFont(SpString const & fontPath) {
	this->font = Font::getFont(fontPath);
}

void sp::TextRenderer::setText(SpString const & text) {
	this->text = text;
}

void sp::TextRenderer::generateRenderData() {
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	unsigned int const stride = (4 * sizeof(float));
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, stride, 0);
	glEnableVertexAttribArray(0);

	unsigned int const quadSize = sizeof(float) * 4 * 6;
	glBufferData(GL_ARRAY_BUFFER, quadSize, NULL, GL_DYNAMIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

sp::Vector2 const sp::TextRenderer::getPosition() const {
	std::weak_ptr<Transform> transformWeak = this->getGameObject()->getComponent<Transform>();
	
	if (auto transformShared = transformWeak.lock()) {
		return transformShared->getPosition();
	}

	return Vector2::getVectorZero();
}

sp::Vector2 const sp::TextRenderer::getScale() const {
	std::weak_ptr<Transform> transformWeak = this->getGameObject()->getComponent<Transform>();

	if (auto transformShared = transformWeak.lock()) {
		return transformShared->getScale();
	}

	return Vector2::getVectorOne();
}
