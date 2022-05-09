#include "CopyMachine.hpp"

CopyMachine::CopyMachine() {

}

CopyMachine::CopyMachine(std::string filename, std::string s1, std::string s2) {
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

int CopyMachine::openFiles(std::ifstream& readFile, std::ofstream& writeFile) {
	readFile.open(filename);
	if (!readFile.is_open()) {
		std::cout << "Failed to open " << filename << std::endl;
		return (1);
	}
	writeFile.open(filename + ".replace");
	if (!writeFile.is_open()) {
		std::cout << "Failed to open " << filename + ".replace" << std::endl;
		return (1);
	}
	return (0);
}

int	CopyMachine::writeToCopiedFile() {
	std::ifstream readFile;
	std::ofstream writeFile;
	std::string string;
	std::string::size_type prev;
	std::string::size_type index;

	if (openFiles(readFile, writeFile)) {
		return (1);
	}
	while (!readFile.eof()) {
		getline(readFile, string);
		if (!readFile.eof()) {
			string += "\n";
		}
		prev = 0;
		while (prev < string.size() && (index = string.find(s1, prev)) != std::string::npos) {
			writeFile << string.substr(prev, index - prev);
			writeFile << s2;
			prev = std::min(index + s1.size(), string.size());
		}
		writeFile << string.substr(prev);
	}
	writeFile.close();
	readFile.close();
	return (0);
}