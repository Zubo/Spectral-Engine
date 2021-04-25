#pragma once

#include <Core/Exception/SpException.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class ShaderProgramLinkingException : public SpException {
	public:
		ShaderProgramLinkingException(SpUnsigned const programId, char const infoLog[]);
		char const * what() const noexcept override;

	private:
		SpUnsigned const _programId;
	};
}
