#include <iostream>

#include "Shader/Shader.h"
#include "Shader/ShaderProgram.h"
#include "Shader/ShaderProgramLinkingException.h"

namespace sp {
	ShaderProgram::ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath) {
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

	void ShaderProgram::setBool(std::string const & name, bool value) const {
		int uniformLocation = glGetUniformLocation(this->id, name.c_str());
		glUniform1i(uniformLocation, (int)value);
	}

	void ShaderProgram::setInt(std::string const & name, int value) const {
		int uniformLocation = glGetUniformLocation(this->id, name.c_str());
		glUniform1i(uniformLocation, value);
	}

	void ShaderProgram::setFloat(std::string const & name, float value) const {
		int uniformLocation = glGetUniformLocation(this->id, name.c_str());
		glUniform1f(uniformLocation, value);
	}

	void ShaderProgram::setMatrix4fv(std::string const & name, float const * const matrix) const {
		int uniformLocation = glGetUniformLocation(this->getId(), name.c_str());
		glUniformMatrix4fv(uniformLocation, 1, GL_TRUE, matrix);
	}

	void ShaderProgram::setVec3(std::string const & name, float x, float y, float z) const {
		int uniformLocation = glGetUniformLocation(this->getId(), name.c_str());
		float value[3] { x, y, z };
		glUniform3fv(uniformLocation, 1, value);
	}
}
