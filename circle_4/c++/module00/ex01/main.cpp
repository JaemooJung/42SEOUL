#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phoneBook;
	std::string command;

	while (1) {
		std::cout << "Enter a command(ADD or SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			phoneBook.searchIndex();
		}
		else if (command == "EXIT") {
			break;
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
}