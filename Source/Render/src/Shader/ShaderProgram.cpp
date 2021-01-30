#include <iostream>

#include "Render/Shader/Shader.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/Shader/ShaderProgramLinkingException.h"

namespace sp {
	ShaderProgram::ShaderProgram(SpString vertexShaderPath, SpString fragmentShaderPath) {
		id = glCreateProgram();
	
		Shader vertexShader{ vertexShaderPath, GL_VERTEX_SHADER };
		glAttachShader(id, vertexShader.getId());
		Shader fragmentShader{ fragmentShaderPath, GL_FRAGMENT_SHADER };
		glAttachShader(id, fragmentShader.getId());

		glLinkProgram(id);

		SpInt success;
		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(id, 512, NULL, infoLog);
			std::cout << infoLog;
			throw ShaderProgramLinkingException{ id, infoLog };
		}

		glDeleteShader(vertexShader.getId());
		glDeleteShader(fragmentShader.getId());
	}

	ShaderProgram::~ShaderProgram() {
	}

	void ShaderProgram::use() const {
		glUseProgram(id);
	}

	SpUnsigned ShaderProgram::getId() const {
		return id;
	}

	void ShaderProgram::setBool(SpString const & name, bool value) const {
		use();
		SpInt const uniformLocation = glGetUniformLocation(id, name.c_str());
		glUniform1i(uniformLocation, (int)value);
	}

	void ShaderProgram::setInt(SpString const & name, SpInt value) const {
		use();
		SpInt const uniformLocation = glGetUniformLocation(id, name.c_str());
		glUniform1i(uniformLocation, value);
	}

	void ShaderProgram::setFloat(SpString const & name, SpFloat value) const {
		use();
		SpInt const uniformLocation = glGetUniformLocation(id, name.c_str());
		glUniform1f(uniformLocation, value);
	}

	void ShaderProgram::setMatrix4fv(SpString const & name, SpFloat const * const matrix) const {
		use();
		SpInt const uniformLocation = glGetUniformLocation(getId(), name.c_str());
		glUniformMatrix4fv(uniformLocation, 1, GL_TRUE, matrix);
	}

	void ShaderProgram::setVec3(SpString const & name, SpFloat x, SpFloat y, SpFloat z) const {
		use();
		SpInt const uniformLocation = glGetUniformLocation(getId(), name.c_str());
		SpFloat value[3] { x, y, z };
		glUniform3fv(uniformLocation, 1, value);
	}
}
