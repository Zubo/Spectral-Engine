#include <sstream>

#include <Render/Shader/ShaderCompilationException.hpp>

namespace sp {
	ShaderCompilationException::ShaderCompilationException(SpUnsigned const shaderId, GLenum shaderType, char infoLog[512])
		: SpException{ infoLog }, _shaderId{ shaderId }, _shaderType{ shaderType } {
	}

	char const * ShaderCompilationException::what() const noexcept {
		std::stringstream ss;
		ss << "Error: shader with id: " << _shaderId << ", type: " << _shaderType << " failed to compile." << std::endl << SpException::what();
		return ss.str().c_str();
	}
}
