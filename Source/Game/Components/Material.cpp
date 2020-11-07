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
		_diffuseColor{ 1.0F },
		_specularColor{ 1.0F },
		_shininess{ 1.0F } {
	}

	void Material::initMaterial(SpString const & vertexShaderPath, SpString const & fragmentShaderPath) {
		ShaderProgram const shaderProgram{ vertexShaderPath, fragmentShaderPath };
		SpInt const gameObjectId = _gameObjectOwner->getId();

		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };

		renderContext.updateShaderProgram(gameObjectId, shaderProgram);
		setAmbient(_ambientColor);
		setSpecular(_specularColor);
		setDiffuse(_diffuseColor);
		setShinines(_shininess);
		shaderProgram.setInt(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".diffuseMapTex" }, 0);
		shaderProgram.setInt(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".specularMapTex" }, 1);
	}

	void Material::setAmbient(Vector3 const & ambientColor) {
		_ambientColor = ambientColor;
		ShaderProgram const shaderProgram = getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".ambient" },
			_ambientColor.X, _ambientColor.Y, _ambientColor.Z);
	}

	void Material::setDiffuse(Vector3 const & diffuseColor) {
		_diffuseColor = diffuseColor;
		ShaderProgram const shaderProgram = getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".diffuse" },
			_diffuseColor.X, _diffuseColor.Y, _diffuseColor.Z);
	}

	void Material::setSpecular(Vector3 const & specularColor) {
		_specularColor = specularColor;
		ShaderProgram const shaderProgram = getShaderProgram();
		shaderProgram.setVec3(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".specular" },
			_specularColor.X, _specularColor.Y, _specularColor.Z);
	}

	void Material::setShinines(SpFloat const shininess) {
		_shininess = shininess;

		ShaderProgram const shaderProgram = getShaderProgram();
		shaderProgram.setFloat(SpString{ MATERIAL_VARIABLE_NAME } + SpString{ ".shininess" },
			_shininess);
	}

	void Material::setDiffuseMap(SpString const & texturePath) {
		TextureManager & textureManager = TextureManager::getInstance();
		Texture texture = textureManager.getTexture(texturePath, true, GL_RGBA);

		SpInt const gameObjectId = _gameObjectOwner->getId();
		SpUnsigned const diffuseMapTextureIndex = 0;
		SpUnsigned const textureId = texture.getId();

		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };

		renderContext.updateTextureId(gameObjectId, textureId, diffuseMapTextureIndex);
	}

	void Material::setSpecularMap(SpString const & texturePath) {
		TextureManager & textureManager = TextureManager::getInstance();
		Texture texture = textureManager.getTexture(texturePath, true, GL_RGBA);

		SpInt const gameObjectId = _gameObjectOwner->getId();
		SpUnsigned const specularMapTextureIndex = 1;
		SpUnsigned const textureId = texture.getId();

		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };

		renderContext.updateTextureId(gameObjectId, textureId, specularMapTextureIndex);
	}

	ShaderProgram const Material::getShaderProgram() {
		SpInt const gameObjectId = _gameObjectOwner->getId();
		
		RenderContext & renderContext{ _gameObjectOwner->GetSceneRef()->getRenderContext() };

		RenderData const & renderData = renderContext.getRenderDataContainer().getRenderData(gameObjectId);

		return renderData.RenderShaderProgram;
	}
}
