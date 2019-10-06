#include "Render/Mesh.h"

#include <algorithm>

namespace sp {
	Mesh::Mesh(
		float const * const dataArray, int const arraySize, unsigned int const * const elementIndices,
		int const indexCount, bool const uvCoords, bool const normalCoords) :
		dataArray{ new float[arraySize] },
		dataArraySize{ arraySize },
		elementIndices{ new unsigned int[indexCount] },
		indexCount{ indexCount },
		uvCoords{ uvCoords },
		normalCoords{ normalCoords } {
		std::copy(dataArray, &dataArray[arraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[indexCount], this->elementIndices);
	}

	Mesh::Mesh(Mesh const & Mesh) :
		dataArray{ new float[Mesh.dataArraySize] },
		dataArraySize{ Mesh.dataArraySize },
		elementIndices{ new unsigned int[Mesh.indexCount] },
		indexCount{ Mesh.indexCount },
		uvCoords{ Mesh.uvCoords },
		normalCoords{ Mesh.normalCoords } {
		std::copy(dataArray, &dataArray[Mesh.dataArraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[Mesh.indexCount], this->elementIndices);
	}

	Mesh::Mesh(Mesh && Mesh) :
		dataArray{ Mesh.dataArray },
		dataArraySize{ Mesh.dataArraySize },
		elementIndices{ Mesh.elementIndices },
		indexCount{ Mesh.indexCount },
		uvCoords{ Mesh.uvCoords },
		normalCoords{ Mesh.normalCoords } {
		float ** dataArrayNoConst = const_cast<float **>(&Mesh.dataArray);
		*dataArrayNoConst = nullptr;
		unsigned int ** indexArrayNoConst = const_cast<unsigned int **>(&Mesh.elementIndices);
		*indexArrayNoConst = nullptr;
	}

	Mesh::~Mesh() {
		delete[] this->dataArray;
		delete[] this->elementIndices;
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
