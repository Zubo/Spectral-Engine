#include <sstream>

#include "Shader/ShaderProgramLinkingException.h"

namespace sp {
	ShaderProgramLinkingException::ShaderProgramLinkingException(unsigned int const programId, char const infoLog[])
		: programId{ programId }, infoLog{ SpString{infoLog} } {
	}

	SpString ShaderProgramLinkingException::what() {
		std::stringstream ss;
		ss << "Error linking program with id: " << this->programId << std::endl << this->infoLog;
		return ss.str();
	}
}
