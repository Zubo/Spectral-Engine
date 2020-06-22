#pragma once

#include <map>

#include "PlatformIndependence/SpType.h"

namespace sp {
	class Mesh {
	public:
		~Mesh();
		Mesh(Mesh && mesh);

	private:
		friend class MeshContainer;
		Mesh(float const * const mesh, int const arraySize, SpUnsigned const * const elementIndices,
			int const indexCount, bool const uvCoords, bool const normalCoords);
		Mesh(Mesh const & mesh);

	public:
		SpUnsigned getId();
		int const getStride() const;
		float const * const getDataArray() const;
		int const getDataArraySize() const;
		SpUnsigned const * const getIndexArray() const;
		int const getIndexCount() const;
		bool const hasUVCoords() const;
		bool const hasNormalCoords() const;

	private:
		SpUnsigned id;
		float * const dataArray;
		int const dataArraySize;
		SpUnsigned * const elementIndices;
		int const indexCount;
		bool const uvCoords;
		bool const normalCoords;
		static SpUnsigned nextId;
	};
}
