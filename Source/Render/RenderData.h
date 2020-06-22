#pragma once

#include "Core/Math/Vector3.h"
#include "Core/Math/Matrix4x4.h"
#include "PlatformIndependence/SpType.h"
#include "Render/Shader/ShaderProgram.h"

#define MAX_NUMBER_OF_TEXTURES 32

namespace sp {
	class RenderData {
	public:
		RenderData(SpInt const gameObjectId, bool const active, bool const isStatic);
		Matrix4x4 const GetModelMatrix() const;

	public:
		SpInt gameObjectId;
		bool active;
		bool isStatic;
		SpUnsigned VAO;
		SpUnsigned VBO;
		SpUnsigned EBO;
		SpUnsigned elementCount;
		Vector3 position;
		Vector3 rotationEuler;
		Vector3 scale;
		bool modelMatrixChanged;
		ShaderProgram shaderProgram;
		SpUnsigned textureIds[MAX_NUMBER_OF_TEXTURES] = { 0 };
	};
}
