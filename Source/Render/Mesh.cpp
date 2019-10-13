#include "Render/Mesh.h"

#include <algorithm>

namespace sp {
	unsigned int Mesh::nextId = 1;

	Mesh::Mesh(
			float const * const dataArray, int const arraySize, unsigned int const * const elementIndices,
			int const indexCount, bool const uvCoords, bool const normalCoords) :
			id{ Mesh::nextId++ },
			dataArray{ new float[arraySize] },
			dataArraySize{ arraySize },
			elementIndices{ new unsigned int[indexCount] },
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
			elementIndices{ new unsigned int[mesh.indexCount] },
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
		unsigned int ** indexArrayNoConst = const_cast<unsigned int **>(&mesh.elementIndices);
		*indexArrayNoConst = nullptr;
		mesh.id = 0;
	}

	Mesh::~Mesh() {
		delete[] this->dataArray;
		delete[] this->elementIndices;
	}

	unsigned int Mesh::getId() {
		return 0;
	}

	int const Mesh::getStride() const {
		int stride = 3;

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

	int const Mesh::getDataArraySize() const {
		return this->dataArraySize;
	}

	unsigned int const * const Mesh::getIndexArray() const {
		return this->elementIndices;
	}

	int const Mesh::getIndexCount() const {
		return this->indexCount;
	}

	bool const Mesh::hasUVCoords() const {
		return this->uvCoords;
	}

	bool const Mesh::hasNormalCoords() const {
		return this->normalCoords;
	}
}
