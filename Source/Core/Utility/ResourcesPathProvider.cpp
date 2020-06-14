#include "ResourcesPathProvider.h"

namespace sp {
	SpString ResourcesPathProvider::resourcesDirectoryPath;
	SpString ResourcesPathProvider::shaderFilesDirectoryPath;

	SpString const & ResourcesPathProvider::getResourcesDirectoryPath() {
		return resourcesDirectoryPath;
	}

	SpString const & ResourcesPathProvider::getShaderFilesDirectoryPath() {
		return shaderFilesDirectoryPath;
	}

	void ResourcesPathProvider::initializePaths(SpString const & rootPath) {
		// MSVC compiler puts executable into additional Debug/Release directory
#ifdef _WIN32
		resourcesDirectoryPath = rootPath + SpString{ "/../../Resources" };
#else
		resourcesDirectoryPath = rootPath + SpString{ "/../Resources" };
#endif
		shaderFilesDirectoryPath = resourcesDirectoryPath + SpString{ "/Shaders" };
	}
}
