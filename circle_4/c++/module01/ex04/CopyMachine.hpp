#ifndef _COPYMACHINE_HPP_
#define _COPYMACHINE_HPP_

#include <string>
#include <iostream>
#include <fstream>

class CopyMachine {
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		int openFiles(std::ifstream& readFile, std::ofstream& writeFile);

	public:
	CopyMachine();
	CopyMachine(std::string filename, std::string s1, std::string s2);
	int writeToCopiedFile();
};

#endif