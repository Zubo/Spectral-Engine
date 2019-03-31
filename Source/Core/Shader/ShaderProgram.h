#pragma once

#include <string>

namespace sp {
	class ShaderProgram {
	public:
		ShaderProgram() = delete;
		ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath);
		~ShaderProgram();
		void use() const;
		unsigned int const getId() const;
		void setBool(std::string const & name, bool value) const;
		void setInt(std::string const & name, int value) const;
		void setFloat(std::string const & name, float value) const;
		void setMatrix4fv(std::string const & name, float const * const matrix) const;
		void setVec3(std::string const & name, float x, float y, float z) const;

	private:
		unsigned int id;
	};
}
