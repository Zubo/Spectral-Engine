#pragma once

#include <glad/glad.h>
#include <iostream>
#include "PlatformIndependence/SpString.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class Shader {
	public:
		Shader(SpString const & filePath, GLenum const);
		~Shader();
	
	public:
		inline SpUnsigned getId() {
			return this->id;
		};
		inline GLenum getType() {
			return this->type;
		};

	private:
		SpUnsigned id;
		GLenum type;
	};
}
