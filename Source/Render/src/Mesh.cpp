#include <Render/Mesh.hpp>

#include <algorithm>

namespace sp {
	SpUnsigned Mesh::_nextId = 1;

	Mesh::Mesh(
			SpFloat const * const dataArray, SpInt const arraySize, SpUnsigned const * const elementIndices,
			SpInt const indexCount, bool const uvCoords, bool const normalCoords) :
			_id{ Mesh::_nextId++ },
			_dataArray{ new float[arraySize] },
			_dataArraySize{ arraySize },
			_elementIndices{ new SpUnsigned[indexCount] },
			_indexCount{ indexCount },
			_uvCoords{ uvCoords },
			_normalCoords{ normalCoords } {
		std::copy(dataArray, &dataArray[arraySize], _dataArray);
		std::copy(elementIndices, &elementIndices[indexCount], _elementIndices);
	}

	Mesh::Mesh(Mesh const & mesh) :
			_id{ Mesh::_nextId++ },
			_dataArray{ new float[mesh._dataArraySize] },
			_dataArraySize{ mesh._dataArraySize },
			_elementIndices{ new SpUnsigned[mesh._indexCount] },
			_indexCount{ mesh._indexCount },
			_uvCoords{ mesh._uvCoords },
			_normalCoords{ mesh._normalCoords } {
		std::copy(mesh._dataArray, &mesh._dataArray[mesh._dataArraySize], _dataArray);
		std::copy(mesh._elementIndices, &mesh._elementIndices[mesh._indexCount], _elementIndices);
	}

	Mesh::Mesh(Mesh && mesh) noexcept :
			_id{ mesh._id },
			_dataArray{ mesh._dataArray },
			_dataArraySize{ mesh._dataArraySize },
			_elementIndices{ mesh._elementIndices },
			_indexCount{ mesh._indexCount },
			_uvCoords{ mesh._uvCoords },
			_normalCoords{ mesh._normalCoords } {
		SpFloat ** dataArrayNoConst = const_cast<SpFloat **>(&mesh._dataArray);
		*dataArrayNoConst = nullptr;
		SpUnsigned ** indexArrayNoConst = const_cast<SpUnsigned **>(&mesh._elementIndices);
		*indexArrayNoConst = nullptr;
		mesh._id = 0;
	}

	Mesh::~Mesh() {
		delete[] _dataArray;
		delete[] _elementIndices;
	}

	SpUnsigned Mesh::getId() {
		return _id;
	}

	SpInt Mesh::getStride() const {
		SpInt stride = 3;

		if (_uvCoords) {
			stride += 2;
		}

		if (_normalCoords) {
			stride += 3;
		}

		return stride;
	}

	sp::SpFloat const * Mesh::getDataArray() const {
		return _dataArray;
	}

	sp::SpInt Mesh::getDataArraySize() const {
		return _dataArraySize;
	}

	sp::SpUnsigned const * Mesh::getIndexArray() const {
		return _elementIndices;
	}

	sp::SpInt Mesh::getIndexCount() const {
		return _indexCount;
	}

	bool Mesh::hasUVCoords() const {
		return _uvCoords;
	}

	bool Mesh::hasNormalCoords() const {
		return _normalCoords;
	}
}
