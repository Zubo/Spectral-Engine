#include "Render/MeshContainer.h"

#include <memory>

#include "PlatformIndependence/SpType.h"
#include "Render/Mesh.h"

namespace sp {
	std::map<SpUnsigned const, Mesh> MeshContainer::_meshMap;

	Mesh const & MeshContainer::getMesh(SpUnsigned const meshId) {
		return MeshContainer::_meshMap.at(meshId);
	}

	SpUnsigned MeshContainer::createMesh(SpFloat const * const dataArray, SpInt const arraySize, SpUnsigned const * const elementIndices,
		SpInt const indexCount, bool const uvCoords, bool const normalCoords) {
		Mesh mesh{ dataArray, arraySize, elementIndices, indexCount, uvCoords, normalCoords };
		SpUnsigned const id = mesh.getId();
		MeshContainer::_meshMap.emplace(id, std::move(mesh));
		return id;
	}
}
