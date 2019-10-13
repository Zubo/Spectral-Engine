#pragma once

#include <map>

namespace sp {
	class Mesh;

	class MeshContainer {
	public:
		static Mesh const & getMesh(unsigned int const meshId);
		static unsigned int createMesh(float const * const dataArray, int const arraySize, unsigned int const * const elementIndices,
			int const indexCount, bool const uvCoords, bool const normalCoords);

	private:
		static std::map<unsigned int const, Mesh> meshMap;
	};
}
