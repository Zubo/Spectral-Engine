#pragma once

#include "Core/Math/Vector3.h"
#include "Core/Math/Matrix4x4.h"
#include "Render/Shader/ShaderProgram.h"

namespace sp {
	class RenderData {
	public:
		RenderData(int const gameObjectId, bool const active, bool const isStatic);
		Matrix4x4 const GetModelMatrix() const;

	public:
		RenderData const & operator=(RenderData const & renderData);

	public:
		int gameObjectId;
		bool active;
		bool isStatic;
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;
		unsigned int elementCount;
		Vector3 translation;
		Vector3 rotationEuler;
		Vector3 scale;
		bool modelMatrixChanged;
		ShaderProgram shaderProgram;
	};
}
