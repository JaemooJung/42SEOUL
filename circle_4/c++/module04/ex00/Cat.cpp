#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << _type << " is making sound: " << "MEOW MEOW MEOW" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other.getType();
	}
	std::cout << _type << " copy assignment constructor called" << std::endl;
	return *this;
}

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << _type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << _type << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type << " destructor called" << std::endl;
}
