#pragma once

namespace sp {
	class RenderData {
	public:
		RenderData(
			float const * const dataArray, int const arraySizeint, unsigned int const * const elementIndices, int const indexCount, bool const uvCoords, bool const normalCoords);
		RenderData(RenderData const & renderData);
		RenderData(RenderData && renderData);
		~RenderData();

	public:
		int const getStride() const;
		float const * const getDataArray() const;
		int const getDataArraySize() const;
		unsigned int const * const getIndexArray() const;
		int const getIndexCount() const;
		bool const hasUVCoords() const;
		bool const hasNormalCoords() const;

	public:
		RenderData const & operator=(RenderData const & renderData);

	private:
		float * const dataArray;
		int const dataArraySize;
		unsigned int * const elementIndices;
		int const indexCount;
		bool const uvCoords;
		bool const normalCoords;
	};
}
