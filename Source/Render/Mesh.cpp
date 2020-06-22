#include "Render/Mesh.h"

#include <algorithm>

namespace sp {
	SpUnsigned Mesh::nextId = 1;

	Mesh::Mesh(
			float const * const dataArray, SpInt const arraySize, SpUnsigned const * const elementIndices,
			SpInt const indexCount, bool const uvCoords, bool const normalCoords) :
			id{ Mesh::nextId++ },
			dataArray{ new float[arraySize] },
			dataArraySize{ arraySize },
			elementIndices{ new SpUnsigned[indexCount] },
			indexCount{ indexCount },
			uvCoords{ uvCoords },
			normalCoords{ normalCoords } {
		std::copy(dataArray, &dataArray[arraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[indexCount], this->elementIndices);
	}

	Mesh::Mesh(Mesh const & mesh) :
			id{ Mesh::nextId++ },
			dataArray{ new float[mesh.dataArraySize] },
			dataArraySize{ mesh.dataArraySize },
			elementIndices{ new SpUnsigned[mesh.indexCount] },
			indexCount{ mesh.indexCount },
			uvCoords{ mesh.uvCoords },
			normalCoords{ mesh.normalCoords } {
		std::copy(dataArray, &dataArray[mesh.dataArraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[mesh.indexCount], this->elementIndices);
	}

	Mesh::Mesh(Mesh && mesh) :
			id{ mesh.id },
			dataArray{ mesh.dataArray },
			dataArraySize{ mesh.dataArraySize },
			elementIndices{ mesh.elementIndices },
			indexCount{ mesh.indexCount },
			uvCoords{ mesh.uvCoords },
			normalCoords{ mesh.normalCoords } {
		float ** dataArrayNoConst = const_cast<float **>(&mesh.dataArray);
		*dataArrayNoConst = nullptr;
		SpUnsigned ** indexArrayNoConst = const_cast<SpUnsigned **>(&mesh.elementIndices);
		*indexArrayNoConst = nullptr;
		mesh.id = 0;
	}

	Mesh::~Mesh() {
		delete[] this->dataArray;
		delete[] this->elementIndices;
	}

	SpUnsigned Mesh::getId() {
		return this->id;
	}

	SpInt const Mesh::getStride() const {
		SpInt stride = 3;

		if (uvCoords) {
			stride += 2;
		}

		if (normalCoords) {
			stride += 3;
		}

		return stride;
	}

	float const * const Mesh::getDataArray() const {
		return this->dataArray;
	}

	SpInt const Mesh::getDataArraySize() const {
		return this->dataArraySize;
	}

	SpUnsigned const * const Mesh::getIndexArray() const {
		return this->elementIndices;
	}

	SpInt const Mesh::getIndexCount() const {
		return this->indexCount;
	}

	bool const Mesh::hasUVCoords() const {
		return this->uvCoords;
	}

	bool const Mesh::hasNormalCoords() const {
		return this->normalCoords;
	}
}
