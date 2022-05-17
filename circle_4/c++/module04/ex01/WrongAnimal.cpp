#include "WrongAnimal.hpp"

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(std::string type) {
	_type = type;
}


void WrongAnimal::makeSound() const {
	std::cout << _type << " is making sound." << std::endl;
}

WrongAnimal::WrongAnimal() {
	_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	_type = type;
	std::cout << "WrongAnimal [" << _type << "] constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	_type = other.getType();
	std::cout << "WrongAnimal [" << _type << "] copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other.getType();
	}
	std::cout << "WrongAnimal [" << _type << "] copy assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal [" << _type << "] destructor called" << std::endl;	
}
