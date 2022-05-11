#include "Harl.hpp"

Harl::Harl() {
	debugMessage = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	infoMessage = "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!";
	warningMessage = "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.";
	errorMessage = "This is unacceptable! I want to speak to the manager now.";
}

Harl::~Harl() {

}

void Harl::debug(void) {
	std::cout << "[DEBUG]: " << debugMessage << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]: " << infoMessage << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]: "<< warningMessage << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]: "<< errorMessage << std::endl;
}

void Harl::complain(std::string level) {
	std::string commands[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int message = -1;
	
	for (int i = 0; i < 4; i++) {
		if (level == commands[i]) {
			message = i;
			break;
		}
	}
	switch (message) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" <<std::endl;
	}
}
