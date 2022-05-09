#include "CopyMachine.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./SedIsForLosers [filename] [s1] [s2]" << std::endl;
		return (1);
	}
	CopyMachine copyMachine = CopyMachine(argv[1], argv[2], argv[3]);
	return (copyMachine.writeToCopiedFile());
}