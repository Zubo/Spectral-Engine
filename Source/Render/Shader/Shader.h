#pragma once

#include <glad/glad.h>
#include <iostream>
#include "PlatformIndependence/SpString.h"

namespace sp {
	class Shader {
	public:
		Shader(SpString const & filePath, GLenum const);
		~Shader();
	
	public:
		inline unsigned int getId() {
			return this->id;
		};
		inline GLenum getType() {
			return this->type;
		};

	private:
		unsigned int id;
		GLenum type;
	};
}
