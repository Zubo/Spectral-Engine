#include <Core/FileReader.hpp>

#include <fstream>
#include <streambuf>
#include <sstream>

namespace sp {
	SpString const FileReader::ReadFromFile(SpString const path) {
		std::ifstream inputFileStream{ path.c_str() };

		if (!inputFileStream) {
			throw "File could not be open.";
		}

		SpString shaderString{ std::istreambuf_iterator<char>(inputFileStream), std::istreambuf_iterator<char>() };

		inputFileStream.close();

		return shaderString;
	}
}
