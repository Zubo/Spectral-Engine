#include "PlatformIndependence/SpString.h"

#include "Game/Components/Material.h"
#include "Game/GameObject/GameObject.h"
#include "Render/RenderData.h"
#include "Render/RenderDataContainer.h"
#include "Render/RenderDataUpdate.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/Texture.h"

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
	}

	void Material::setDiffuseMap(SpString const & texturePath) {
		ShaderProgram const shaderProgram = getShaderProgram();
		
		shaderProgram.use();
		this->diffuseMapTexture = std::make_unique<Texture>(texturePath, true, GL_RGBA);
		SpString const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		shaderProgram.setInt(materialVariablePrefix + SpString{ ".diffuseMapTex" }, 0);
	}

	void Material::setSpecularMap(SpString const & texturePath) {
		
		ShaderProgram const shaderProgram = getShaderProgram();
		shaderProgram.use();
		glActiveTexture(GL_TEXTURE1);
		this->specularMapTexture = std::make_unique<Texture>(texturePath, true, GL_RGBA);
		SpString const materialVariablePrefix{ MATERIAL_VARIABLE_NAME };
		shaderProgram.setInt(materialVariablePrefix + SpString{ ".specularMapTex" }, 1);
		glActiveTexture(0);
	}

	ShaderProgram const Material::getShaderProgram() {
		int const gameObjectId = this->gameObjectOwner->getId();
		RenderDataContainer const & renderDataContainer = RenderDataContainer::getInstance();
		RenderData const & renderData = renderDataContainer.getRenderData(gameObjectId);

		return renderData.shaderProgram;
	}
}
