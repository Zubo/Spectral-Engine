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
		_ambientColor{ 1.0F },
		_specularColor{ 1.0F },
		_diffuseColor{ 1.0F },
		_shininess{ 1.0F } {
	}

	void Material::initMaterial(SpString const & vertexShaderPath, SpString const & fragmentShaderPath) {
		ShaderProgram const shaderProgram{ vertexShaderPath, fragmentShaderPath };
		SpInt const gameObjectId = this->_gameObjectOwner->getId();
		updateShaderProgram(gameObjectId, shaderProgram);
		this->setAmbient(this->_ambientColor);
		this->setSpecular(this->_specularColor);
		this->setDiffuse(this->_diffuseColor);
		this->setShinines(this->_shininess);
		shaderProgram.setInt(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".diffuseMapTex" }, 0);
		shaderProgram.setInt(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".specularMapTex" }, 1);
	}

	void Material::setAmbient(Vector3 const & ambientColor) {
		this->_ambientColor = ambientColor;
		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".ambient" },
			this->_ambientColor.X, this->_ambientColor.Y, this->_ambientColor.Z);
	}

	void Material::setDiffuse(Vector3 const & diffuseColor) {
		this->_diffuseColor = diffuseColor;
		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".diffuse" },
			this->_diffuseColor.X, this->_diffuseColor.Y, this->_diffuseColor.Z);
	}

	void Material::setSpecular(Vector3 const & specularColor) {
		this->_specularColor = specularColor;
		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".specular" },
			this->_specularColor.X, this->_specularColor.Y, this->_specularColor.Z);
	}

	void Material::setShinines(SpFloat const shininess) {
		this->_shininess = shininess;

		ShaderProgram const shaderProgram = this->getShaderProgram();
		shaderProgram.setFloat(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".shininess" },
			this->_shininess);
	}

	void Material::setDiffuseMap(SpString const & texturePath) {
		TextureManager & textureManager = TextureManager::getInstance();
		Texture texture = textureManager.getTexture(texturePath, true, GL_RGBA);

		SpInt const gameObjectId = this->_gameObjectOwner->getId();
		SpUnsigned const diffuseMapTextureIndex = 0;
		SpUnsigned const textureId = texture.getId();
		updateTextureId(gameObjectId, textureId, diffuseMapTextureIndex);
	}

	void Material::setSpecularMap(SpString const & texturePath) {
		TextureManager & textureManager = TextureManager::getInstance();
		Texture texture = textureManager.getTexture(texturePath, true, GL_RGBA);

		SpInt const gameObjectId = this->_gameObjectOwner->getId();
		SpUnsigned const specularMapTextureIndex = 1;
		SpUnsigned const textureId = texture.getId();
		updateTextureId(gameObjectId, textureId, specularMapTextureIndex);
	}

	ShaderProgram const Material::getShaderProgram() {
		SpInt const gameObjectId = this->_gameObjectOwner->getId();
		RenderDataContainer const & renderDataContainer = RenderDataContainer::getInstance();
		RenderData const & renderData = renderDataContainer.getRenderData(gameObjectId);

		return renderData.ShaderProgram;
	}
}
