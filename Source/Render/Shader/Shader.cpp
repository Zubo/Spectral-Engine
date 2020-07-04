#include <iostream>

#include "Core/FileReader.h"
#include "Render/Shader/Shader.h"
#include "Render/Shader/ShaderCompilationException.h"

namespace sp {
	Shader::Shader(SpString const & filePath, GLenum const type) : type{ type } {
		id = glCreateShader(type);

		SpString shaderText = FileReader::ReadFromFile(filePath);
		char const * const shaderSourceCstring = shaderText.c_str();

		glShaderSource(id, 1, &shaderSourceCstring, NULL);
		glCompileShader(id);

		SpInt success;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);

		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(id, sizeof(infoLog), NULL, infoLog);
			std::cout << infoLog;
			throw ShaderCompilationException{ id, type, infoLog };
		}
	}

	Shader::~Shader() {
	}
}
