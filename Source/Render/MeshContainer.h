#pragma once

#include <map>

#include "PlatformIndependence/SpType.h"

namespace sp {
	class Mesh;

	class MeshContainer {
	public:
		static Mesh const & getMesh(SpUnsigned const meshId);
		static SpUnsigned createMesh(SpFloat const * const dataArray, SpInt const arraySize, SpUnsigned const * const elementIndices,
			SpInt const indexCount, bool const uvCoords, bool const normalCoords);

	private:
		static std::map<SpUnsigned const, Mesh> meshMap;
	};
}
