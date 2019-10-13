#include "MeshContainer.h"

#include <memory>

#include "Render/Mesh.h"

namespace sp {
	std::map<unsigned int const, Mesh> MeshContainer::meshMap;

	Mesh const & MeshContainer::getMesh(unsigned int const meshId) {
		return MeshContainer::meshMap.at(meshId);
	}

	unsigned int MeshContainer::createMesh(float const * const dataArray, int const arraySize, unsigned int const * const elementIndices,
		int const indexCount, bool const uvCoords, bool const normalCoords) {
		Mesh mesh{ dataArray, arraySize, elementIndices, indexCount, uvCoords, normalCoords };
		unsigned int const id = mesh.getId();
		MeshContainer::meshMap.emplace(id, std::move(mesh));
		return id;
	}
}
