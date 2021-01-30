#pragma once

#include <glad/glad.h>
#include <iostream>
#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class Shader {
	public:
		Shader(SpString const & filePath, GLenum const);
		~Shader();
	
	public:
		inline SpUnsigned getId() {
			return id;
		};
		inline GLenum getType() {
			return type;
		};

	private:
		SpUnsigned id;
		GLenum type;
	};
}
