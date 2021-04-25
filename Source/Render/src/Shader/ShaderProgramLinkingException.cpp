#include <sstream>

#include <Render/Shader/ShaderProgramLinkingException.hpp>

namespace sp {
	ShaderProgramLinkingException::ShaderProgramLinkingException(SpUnsigned const programId, char const infoLog[]) :
		SpException{ infoLog },
		_programId{ programId } {
	}

	char const * ShaderProgramLinkingException::what() const {
		std::stringstream ss;
		ss << "Error linking program with id: " << _programId << std::endl << SpException::what();
		return ss.str().c_str();
	}
}
