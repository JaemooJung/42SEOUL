#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <input>" << std::endl;
		return 1;
	}
	std::cout << Converter(argv[1]);
	return 0;
}