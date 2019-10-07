#pragma once

#include "Core/Math/Matrix4x4.h"
#include "Render/Shader/ShaderProgram.h"

namespace sp {
	class RenderData {
	public:
		RenderData(int const gameObjectId, ShaderProgram const shaderProgram, bool const active, bool isStatic);

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
		Matrix4x4 mvpMatrix;
		bool changedMVP;
		ShaderProgram shaderProgram;
	};
}
