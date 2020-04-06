#include "PlatformIndependence/SpString.h"

#include "Game/Components/Material.h"
#include "Game/GameObject/GameObject.h"
#include "Render/RenderData.h"
#include "Render/RenderDataContainer.h"
#include "Render/RenderDataUpdate.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/Texture.h"
#include "Render/TextureManager.h"

#define MATERIAL_VARIABLE_NAME "material"

namespace sp {
	Material::Material(GameObject * gameObject) : GameObjectComponent(gameObject),
		ambientColor{ 1.0F },
		specularColor{ 1.0F },
		diffuseColor{ 1.0F },
		shininess{ 1.0F } {
	}

	void Material::initMaterial(SpString const & vertexShaderPath, SpString const & fragmentShaderPath) {
		ShaderProgram const shaderProgram{ vertexShaderPath, fragmentShaderPath };
		int const gameObjectId = this->gameObjectOwner->getId();
		updateShaderProgram(gameObjectId, shaderProgram);
		this->setAmbient(this->ambientColor);
		this->setSpecular(this->specularColor);
		this->setDiffuse(this->diffuseColor);
		this->setShinines(this->shininess);
		shaderProgram.setInt(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".diffuseMapTex" }, 0);
		shaderProgram.setInt(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".specularMapTex" }, 1);
	}

	void Material::setAmbient(Vector3 const & ambientColor) {
		this->ambientColor = ambientColor;
		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".ambient" },
			this->ambientColor.x, this->ambientColor.y, this->ambientColor.z);
	}

	void Material::setDiffuse(Vector3 const & diffuseColor) {
		this->diffuseColor = diffuseColor;
		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".diffuse" },
			this->diffuseColor.x, this->diffuseColor.y, this->diffuseColor.z);
	}

	void Material::setSpecular(Vector3 const & specularColor) {
		this->specularColor = specularColor;
		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".specular" },
			this->specularColor.x, this->specularColor.y, this->specularColor.z);
	}

	void Material::setShinines(float const shininess) {
		this->shininess = shininess;

		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setFloat(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".shininess" },
			this->shininess);
	}

	void Material::setDiffuseMap(SpString const & texturePath) {
		TextureManager & textureManager = TextureManager::getInstance();
		Texture texture = textureManager.getTexture(texturePath, true, GL_RGBA);

		int const gameObjectId = this->gameObjectOwner->getId();
		unsigned int const diffuseMapTextureIndex = 0;
		unsigned int const textureId = texture.getId();
		updateTextureId(gameObjectId, textureId, diffuseMapTextureIndex);
	}

	void Material::setSpecularMap(SpString const & texturePath) {
		TextureManager & textureManager = TextureManager::getInstance();
		Texture texture = textureManager.getTexture(texturePath, true, GL_RGBA);

		int const gameObjectId = this->gameObjectOwner->getId();
		unsigned int const specularMapTextureIndex = 1;
		unsigned int const textureId = texture.getId();
		updateTextureId(gameObjectId, textureId, specularMapTextureIndex);
	}

	ShaderProgram const Material::getShaderProgram() {
		int const gameObjectId = this->gameObjectOwner->getId();
		RenderDataContainer const & renderDataContainer = RenderDataContainer::getInstance();
		RenderData const & renderData = renderDataContainer.getRenderData(gameObjectId);

		return renderData.shaderProgram;
	}
}
