#pragma once

#include <PlatformIndependence/SpString.hpp>

namespace sp {
	class ResourcesPathProvider {
	public:
		static SpString const & getResourcesDirectoryPath();
		static SpString getFullResourcePath(SpString const & resourceRelativePath);
		static SpString const & getShaderFilesDirectoryPath();
		static void initializePaths(SpString const & rootPath);

	private:
		static SpString _resourcesDirectoryPath;
		static SpString _shaderFilesDirectoryPath;

	private:
		ResourcesPathProvider() = delete;
	};
}
