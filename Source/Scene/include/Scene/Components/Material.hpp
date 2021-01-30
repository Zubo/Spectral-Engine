#pragma once

#include <memory>
#include <vector>

#include <Scene/Components/GameObjectComponent.hpp>
#include <Core/Math/Matrix4x4.hpp>
#include <Core/Math/Vector3.hpp>
#include <PlatformIndependence/SpString.hpp>
#include <Render/Shader/ShaderProgram.hpp>
#include <Render/RenderData.hpp>

namespace sp {
	class Texture;

	class Material : public GameObjectComponent {
	public:
		Material(GameObject * gameObject);

	public:
		void initMaterial(SpString const & vertexShaderPath, SpString const & fragmentShaderPath);
		void setAmbient(Vector3 const & ambientColor);
		void setDiffuse(Vector3 const & diffuseColor);
		void setSpecular(Vector3 const & specularColor);
		void setShinines(SpFloat const shininess);
		void setDiffuseMap(SpString const & texturePath);
		void setSpecularMap(SpString const & texturePath);

	private:
		ShaderProgram const getShaderProgram();

	private:
		Vector3 _ambientColor;
		Vector3 _diffuseColor;
		Vector3 _specularColor;
		SpFloat _shininess;
	};
}
