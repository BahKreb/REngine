#pragma once

#include <string>
#include <fstream>

namespace ren {

	namespace util {

		inline std::string read_file(const char* filePath) {
			FILE* file = fopen(filePath, "rt");
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1]{};
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}

	}

}