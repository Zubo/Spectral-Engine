#pragma once

#include <glad/glad.h>
#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class ShaderCompilationException {
	public:
		ShaderCompilationException(SpUnsigned const shaderId, GLenum shaderType, char infoLog[512]);

	public:
		SpString what();

	private:
		SpUnsigned const shaderId;
		GLenum const shaderType;
		SpString const infoLog;
	};
}
