#include "Dog.hpp"

void Dog::makeSound() const {
	std::cout << _type << " is making sound: " << "BOW BOW BOWW" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other.getType();
	}
	std::cout << _type << " copy assignment constructor called" << std::endl;
	return *this;
}

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << _type << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	_type = other.getType();
	std::cout << _type << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type << " destructor called" << std::endl;
}
