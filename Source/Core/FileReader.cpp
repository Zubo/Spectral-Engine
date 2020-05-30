#include "Core/FileReader.h"

namespace sp {
	SpString const FileReader::ReadFromFile(SpString const path) {
		std::ifstream inputFileStream(path);

		if (!inputFileStream) {
			throw "File could not be open.";
		}

		return SpString(std::istreambuf_iterator<char>(inputFileStream), std::istreambuf_iterator<char>());
	}
}
