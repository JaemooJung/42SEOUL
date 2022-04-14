#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	this->currentIndex = 0;
}

PhoneBook::~PhoneBook() {
	
}

std::string PhoneBook::receiveUserInput(std::string message) {
	std::string input;

	while (1) {
		std::getline(std::cin, input);
		if (input.length() > 0) {
			break;
		} else {
			std::cout << "Contact cannot have empty field." << std::endl;
			std::cout << message;
		}
	}
	return (input);
} 

void PhoneBook::addContact() {
	Contact newContact;
	
	std::cout << "Enter first name: ";
	newContact.setFirstName(this->receiveUserInput("Enter first name: "));
	std::cout << "Enter last name: ";
	newContact.setLastName(this->receiveUserInput("Enter last name: "));
	std::cout << "Enter nickname: ";
	newContact.setNickname(this->receiveUserInput("Enter nickname: "));
	std::cout << "Enter phone number: ";
	newContact.setPhoneNumber(this->receiveUserInput("Enter phone number: "));
	std::cout << "Enter darkest secret: ";
	newContact.setSecret(this->receiveUserInput("Enter darkest secret: "));
	this->contact[this->currentIndex % 8] = newContact;
	this->currentIndex++;
}

std::string PhoneBook::cutOver10(std::string str)
{
	if (str.length() >= 10) {
		return (str.substr(0, 9) + ".");
	} else {
		return (str);
	}
}

void PhoneBook::printPhoneBook() {
	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	std::cout << std::setw(43) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setfill(' ');
	for (int i = 0; i < std::min(8, this->currentIndex); i++)
	{ 
		std::cout << std::setw(10) << i + 1 << "|"; 
		std::cout << std::setw(10) << cutOver10(contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << cutOver10(contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << cutOver10(contact[i].getNickname()) << std::endl;
	}
	std::cout << std::setw(43) << std::setfill('=') << "=" << std::endl;
	std::cout << std::setfill(' ');
}

void PhoneBook::searchIndex() {
	int index;

	this->printPhoneBook();
	if (this->currentIndex == 0) {
		std::cout << "Phone book is empty." << std::endl;
		return ;
	}
	while (1) {
		std::cout << "Enter index to search for: ";
		std::cin >> index;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input." << std::endl;
		} else if (index > this->currentIndex || index < 1) {
			std::cout << "Index out of range." << std::endl;
		} else {
			break;
		}
	}
	std::cin.ignore();
	std::cout << std::endl;
	contact[index - 1].showInfo();
	std::cout << std::endl;
}