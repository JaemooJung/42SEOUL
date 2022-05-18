#include "Cat.hpp"


void Cat::makeSound() const {
	std::cout << _type << " is making sound: " << "MEOW MEOW MEOW" << std::endl;
}

Brain* Cat::getBrain() const {
	return _brain;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other.getType();
		*_brain = *other.getBrain();
	}
	std::cout << _type << " copy assignment constructor called" << std::endl;
	return *this;
}

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << _type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other.getBrain())) {
	std::cout << _type << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << _type << " destructor called" << std::endl;
}
