#include <sstream>

#include <PlatformIndependence/SpType.h>
#include <Render/Shader/ShaderProgramLinkingException.h>

namespace sp {
	ShaderProgramLinkingException::ShaderProgramLinkingException(SpUnsigned const programId, char const infoLog[])
		: programId{ programId }, infoLog{ SpString{infoLog} } {
	}

	SpString ShaderProgramLinkingException::what() {
		std::stringstream ss;
		ss << "Error linking program with id: " << programId << std::endl << infoLog;
		return ss.str();
	}
}
