#include "Harl.hpp"

int main(void) {
	Harl harl;
	
	while (true) {
		std::cout << "Enter a level of complaint(DEBUG, INFO, WARNING, ERROR, DONE): ";
		std::string level;
		std::getline(std::cin, level);
		if (level == "DONE") {
			break;
		}
		harl.complain(level);
	}
	return (0);
}