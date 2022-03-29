#ifndef PLATFORM_FILESYS_FILESYSTEM_H_
#define PLATFORM_FILESYS_FILESYSTEM_H_

#include <vector>
#include <string>
#include <fstream>

namespace FileSystem {
/*
 * There is a C-style variant of this method that is 3-4 times faster if performance is needed.
 */
	std::vector<std::string> readLines(const std::string& path) {
		std::ifstream infile(path);
		std::vector<std::string> lines;
		std::string line;

		if (infile.is_open()) {
			while (std::getline(infile, line)) {
				lines.push_back(line);
			}

			infile.close();
		}

		return lines;
	}

	void overwriteFile(const std::string& path, std::string content) {
		std::ofstream outfile(path);

		if (outfile.is_open()) {
			outfile << content;
			outfile.close();
		}
	}
}

#endif /* PLATFORM_FILESYS_FILESYSTEM_H_ */
