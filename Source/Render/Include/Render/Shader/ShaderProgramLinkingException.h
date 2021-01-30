#pragma once

#include <PlatformIndependence/SpString.h>

namespace sp {
	class ShaderProgramLinkingException {
	public:
		ShaderProgramLinkingException(SpUnsigned const programId, char const infoLog[]);
		SpString what();

	private:
		SpUnsigned const programId;
		SpString const infoLog;
	};
}
