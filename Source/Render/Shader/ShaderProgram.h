#pragma once

#include "PlatformIndependence/SpString.h"
#include "PlatformIndependence/SpType.h"

namespace sp {
	class ShaderProgram {
	public:
		ShaderProgram() = default;
		ShaderProgram(SpString vertexShaderPath, SpString fragmentShaderPath);
		~ShaderProgram();
		void use() const;
		SpUnsigned const getId() const;
		void setBool(SpString const & name, bool value) const;
		void setInt(SpString const & name, SpInt value) const;
		void setFloat(SpString const & name, float value) const;
		void setMatrix4fv(SpString const & name, float const * const matrix) const;
		void setVec3(SpString const & name, float x, float y, float z) const;

	private:
		SpUnsigned id;
	};
}
