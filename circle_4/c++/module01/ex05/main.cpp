#include "Harl.hpp"

int main(void) {
	Harl harl;
	std::string level;

	std::cout << "Enter a level of complaint(DEBUG, INFO, WARNING, ERROR, DONE): ";
	while (std::getline(std::cin, level)) {
		if (level == "DONE") {
			break;
		}
		harl.complain(level);
		std::cout << "Enter a level of complaint(DEBUG, INFO, WARNING, ERROR, DONE): ";
	}
	return (0);
}