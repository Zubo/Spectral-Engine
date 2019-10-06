#pragma once

namespace sp {
	class Mesh {
	public:
		Mesh(float const * const mesh, int const arraySize, unsigned int const * const elementIndices,
			int const indexCount, bool const uvCoords, bool const normalCoords);
		Mesh(Mesh const & mesh);
		Mesh(Mesh && mesh);
		~Mesh();

	public:
		int const getStride() const;
		float const * const getDataArray() const;
		int const getDataArraySize() const;
		unsigned int const * const getIndexArray() const;
		int const getIndexCount() const;
		bool const hasUVCoords() const;
		bool const hasNormalCoords() const;

	private:
		float * const dataArray;
		int const dataArraySize;
		unsigned int * const elementIndices;
		int const indexCount;
		bool const uvCoords;
		bool const normalCoords;
	};
}
