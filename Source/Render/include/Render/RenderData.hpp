#pragma once


#include <Core/Math/Vector3.hpp>
#include <Core/Math/Matrix4x4.hpp>
#include <PlatformIndependence/SpType.hpp>
#include <Render/Shader/ShaderProgram.hpp>

#define MAX_NUMBER_OF_TEXTURES 32

namespace sp {
	class RenderData {
	public:
		RenderData(SpInt const gameObjectId, bool const active, bool const isStatic);
		Matrix4x4 const getModelMatrix() const;

	public:
		SpInt GameObjectId;
		bool Active;
		bool IsStatic;
		bool DepthTest = true;
		SpUnsigned VAO;
		SpUnsigned VBO;
		SpUnsigned EBO;
		SpUnsigned ElementCount;
		Vector3 Position;
		Vector3 RotationEuler;
		Vector3 Scale;
		bool ModelMatrixChanged;
		ShaderProgram RenderShaderProgram;
		SpUnsigned TextureIds[MAX_NUMBER_OF_TEXTURES] = { 0 };
	};
}
