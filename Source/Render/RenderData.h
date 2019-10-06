#pragma once

#include "Core/Math/Matrix4x4.h"
#include "Render/Shader/ShaderProgram.h"

namespace sp {
	class RenderData {
	public:
		RenderData const & operator=(RenderData const & renderData);

	public:
		int gameObjectId;
		bool active;
		int VAO;
		int VBO;
		int EBO;
		Matrix4x4 mvpMatrix;
		bool changedMVP;
		ShaderProgram shaderProgram;
	};
}
