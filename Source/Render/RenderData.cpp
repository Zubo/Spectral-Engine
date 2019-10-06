#include "RenderData.h"

#include <algorithm>

namespace sp {
	RenderData::RenderData(
		float const * const dataArray, int const arraySize, unsigned int const * const elementIndices, int const indexCount, bool const uvCoords, bool const normalCoords) :
		dataArray{ new float[arraySize] },
		dataArraySize{ arraySize },
		elementIndices{ new unsigned int[indexCount] },
		indexCount{ indexCount },
		uvCoords { uvCoords },
		normalCoords{ normalCoords } {
		std::copy(dataArray, &dataArray[arraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[indexCount], this->elementIndices);
	}

	RenderData::RenderData(RenderData const & renderData) :
		dataArray { new float[renderData.dataArraySize] },
		dataArraySize{ renderData.dataArraySize },
		elementIndices{ new unsigned int[renderData.indexCount] },
		indexCount{ renderData.indexCount },
		uvCoords{ renderData.uvCoords },
		normalCoords{ renderData.normalCoords } {
		std::copy(dataArray, &dataArray[renderData.dataArraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[renderData.indexCount], this->elementIndices);
	}

	RenderData::RenderData(RenderData && renderData) :
		dataArray{ renderData.dataArray },
		dataArraySize{ renderData.dataArraySize },
		elementIndices{ renderData.elementIndices },
		indexCount{ renderData.indexCount },
		uvCoords{ renderData.uvCoords },
		normalCoords{ renderData.normalCoords } {
		float ** dataArrayNoConst = const_cast<float **>(&renderData.dataArray);
		*dataArrayNoConst = nullptr;
		unsigned int ** indexArrayNoConst = const_cast<unsigned int **>(&renderData.elementIndices);
		*indexArrayNoConst = nullptr;
	}

	RenderData::~RenderData() {
		delete[] this->dataArray;
		delete[] this->elementIndices;
	}

	int const RenderData::getStride() const {
		int stride = 3;

		if (uvCoords) {
			stride += 2;
		}

		if (normalCoords) {
			stride += 3;
		}

		return stride;
	}

	float const * const RenderData::getDataArray() const {
		return this->dataArray;
	}

	int const RenderData::getDataArraySize() const {
		return this->dataArraySize;
	}

	unsigned int const * const RenderData::getIndexArray() const {
		return this->elementIndices;
	}

	int const RenderData::getIndexCount() const {
		return this->indexCount;
	}

	bool const RenderData::hasUVCoords() const {
		return this->uvCoords;
	}

	bool const RenderData::hasNormalCoords() const {
		return this->normalCoords;
	}

	RenderData const & RenderData::operator=(RenderData const & renderData) {
		return RenderData{ renderData };
	}
}
