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
		Mesh(SpFloat const * const mesh, SpInt const arraySize, SpUnsigned const * const elementIndices,
			SpInt const indexCount, bool const uvCoords, bool const normalCoords);
		Mesh(Mesh const & mesh);

	public:
		SpUnsigned getId();
		SpInt const getStride() const;
		SpFloat const * const getDataArray() const;
		SpInt const getDataArraySize() const;
		SpUnsigned const * const getIndexArray() const;
		SpInt const getIndexCount() const;
		bool const hasUVCoords() const;
		bool const hasNormalCoords() const;

	private:
		SpUnsigned _id;
		SpFloat * const _dataArray;
		SpInt const _dataArraySize;
		SpUnsigned * const _elementIndices;
		SpInt const _indexCount;
		bool const _uvCoords;
		bool const _normalCoords;
		static SpUnsigned _nextId;
	};
}
