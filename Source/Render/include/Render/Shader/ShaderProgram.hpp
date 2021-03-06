#pragma once

#include <PlatformIndependence/SpString.hpp>
#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class ShaderProgram {
	public:
		ShaderProgram() = default;
		ShaderProgram(SpString const & vertexShaderPath, SpString const & fragmentShaderPath);
		~ShaderProgram();
		void use() const;
		SpUnsigned getId() const;
		void setBool(SpString const & name, bool value) const;
		void setInt(SpString const & name, SpInt value) const;
		void setFloat(SpString const & name, SpFloat value) const;
		void setMatrix4fv(SpString const & name, SpFloat const * const matrix) const;
		void setVec3(SpString const & name, SpFloat x, SpFloat y, SpFloat z) const;

	private:
		SpUnsigned id;
	};
}
