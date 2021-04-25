#pragma once

#include <glad/glad.h>
#include <Core/Exception/SpException.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class ShaderCompilationException : public SpException {
	public:
		ShaderCompilationException(SpUnsigned const shaderId, GLenum shaderType, char infoLog[512]);

	public:
		char const * what() const override;

	private:
		SpUnsigned const _shaderId;
		GLenum const _shaderType;
	};
}
