#include "Core/Utility/ResourcesPathProvider.h"

namespace sp {
	SpString ResourcesPathProvider::_resourcesDirectoryPath;
	SpString ResourcesPathProvider::_shaderFilesDirectoryPath;

	SpString const & ResourcesPathProvider::getResourcesDirectoryPath() {
		return _resourcesDirectoryPath;
	}

	SpString const & ResourcesPathProvider::getShaderFilesDirectoryPath() {
		return _shaderFilesDirectoryPath;
	}

	void ResourcesPathProvider::initializePaths(SpString const & rootPath) {
		// MSVC compiler puts executable into additional Debug/Release directory
#ifdef _WIN32
		_resourcesDirectoryPath = rootPath + SpString{ "/../../Resources" };
#else
		_resourcesDirectoryPath = rootPath + SpString{ "/../Resources" };
#endif
		_shaderFilesDirectoryPath = _resourcesDirectoryPath + SpString{ "/Shaders" };
	}
}
