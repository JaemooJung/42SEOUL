#include "Animal.hpp"

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(std::string type) {
	_type = type;
}


void Animal::makeSound() const {
	std::cout << _type << " is making sound." << std::endl;
}

Animal::Animal() {
	_type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) {
	_type = type;
	std::cout << "Animal [" << _type << "] constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	_type = other.getType();
	std::cout << "Animal [" << _type << "] copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other.getType();
	}
	std::cout << "Animal [" << _type << "] copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal [" << _type << "] destructor called" << std::endl;	
}
