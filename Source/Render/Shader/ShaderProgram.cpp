#include <iostream>

#include "Render/Shader/Shader.h"
#include "Render/Shader/ShaderProgram.h"
#include "Render/Shader/ShaderProgramLinkingException.h"

namespace sp {
	ShaderProgram::ShaderProgram(SpString vertexShaderPath, SpString fragmentShaderPath) {
		this->id = glCreateProgram();
	
		Shader vertexShader{ vertexShaderPath, GL_VERTEX_SHADER };
		glAttachShader(this->id, vertexShader.getId());
		Shader fragmentShader{ fragmentShaderPath, GL_FRAGMENT_SHADER };
		glAttachShader(this->id, fragmentShader.getId());

		glLinkProgram(this->id);

		int success;
		glGetProgramiv(this->id, GL_LINK_STATUS, &success);

		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(this->id, 512, NULL, infoLog);
			std::cout << infoLog;
			throw ShaderProgramLinkingException{ this->id, infoLog };
		}

		glDeleteShader(vertexShader.getId());
		glDeleteShader(fragmentShader.getId());
	}

	ShaderProgram::~ShaderProgram() {
	}

	void ShaderProgram::use() const {
		glUseProgram(this->id);
	}

	unsigned int const ShaderProgram::getId() const {
		return this->id;
	}

	void ShaderProgram::setBool(SpString const & name, bool value) const {
		int const uniformLocation = glGetUniformLocation(this->id, name.c_str());
		glUniform1i(uniformLocation, (int)value);
	}

	void ShaderProgram::setInt(SpString const & name, int value) const {
		int const uniformLocation = glGetUniformLocation(this->id, name.c_str());
		glUniform1i(uniformLocation, value);
	}

	void ShaderProgram::setFloat(SpString const & name, float value) const {
		int const uniformLocation = glGetUniformLocation(this->id, name.c_str());
		glUniform1f(uniformLocation, value);
	}

	void ShaderProgram::setMatrix4fv(SpString const & name, float const * const matrix) const {
		int const uniformLocation = glGetUniformLocation(this->getId(), name.c_str());
		glUniformMatrix4fv(uniformLocation, 1, GL_TRUE, matrix);
	}

	void ShaderProgram::setVec3(SpString const & name, float x, float y, float z) const {
		int const uniformLocation = glGetUniformLocation(this->getId(), name.c_str());
		float value[3] { x, y, z };
		glUniform3fv(uniformLocation, 1, value);
	}
}
