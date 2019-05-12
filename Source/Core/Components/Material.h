#pragma once

#include <memory>
#include <vector>

#include "Core/Components/GameObjectComponent.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"
#include "PlatformIndependence/SpString.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/VertexData.h"

namespace sp {
	class Texture;

	class Material : public GameObjectComponent {
	public:
		Material(GameObject * gameObject);

	public:
		void initMaterial(SpString const & vertexShaderPath, SpString const & fragmentShaderPath);
		void use(Matrix4x4 const & mvpMatrix, Matrix4x4 const & modelMatrix) const;
		std::weak_ptr<ShaderProgram> getShaderProgram() const;
		void setAmbient(Vector3 const & ambientColor);
		void setDiffuse(Vector3 const & diffuseColor);
		void setSpecular(Vector3 const & specularColor);
		void setShinines(float const shininess);
		void setDiffuseMap(SpString const & texturePath);
		void setSpecularMap(SpString const & texturePath);

	private:
		Vector3 ambientColor;
		Vector3 diffuseColor;
		Vector3 specularColor;
		float shininess;
		std::shared_ptr<ShaderProgram> shaderProgram;
		std::unique_ptr<Texture> diffuseMapTexture;
		std::unique_ptr<Texture> specularMapTexture;
	};
}
