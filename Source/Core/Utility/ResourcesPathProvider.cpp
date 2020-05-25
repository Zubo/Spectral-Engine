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
		resourcesDirectoryPath = rootPath + SpString{ "/../../Resources" };
		shaderFilesDirectoryPath = resourcesDirectoryPath + SpString{ "/Shaders" };
	}
}
