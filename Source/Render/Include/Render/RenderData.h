#pragma once


#include <Core/Math/Vector3.h>
#include <Core/Math/Matrix4x4.h>
#include <PlatformIndependence/SpType.h>
#include <Render/Shader/ShaderProgram.h>

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
