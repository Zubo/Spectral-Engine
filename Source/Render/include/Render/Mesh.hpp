#pragma once

#include <unordered_map>

#include <PlatformIndependence/SpType.hpp>

namespace sp {
	class Mesh {
	public:
		~Mesh();
		Mesh(Mesh && mesh) noexcept;

	private:
		friend class MeshContainer;
		Mesh(SpFloat const * const mesh, SpInt const arraySize, SpUnsigned const * const elementIndices,
			SpInt const indexCount, bool const uvCoords, bool const normalCoords);
		Mesh(Mesh const & mesh);

	public:
		SpUnsigned getId();
		SpInt getStride() const;
		SpFloat const * getDataArray() const;
		SpInt getDataArraySize() const;
		SpUnsigned const * getIndexArray() const;
		SpInt getIndexCount() const;
		bool hasUVCoords() const;
		bool hasNormalCoords() const;

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
