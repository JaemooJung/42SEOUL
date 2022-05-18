#include "Dog.hpp"

void Dog::makeSound() const {
	std::cout << _type << " is making sound: " << "BOW BOW BOW" << std::endl;
}

Brain* Dog::getBrain() const {
	return _brain;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other.getType();
		*_brain = *other.getBrain();
	}
	std::cout << _type << " copy assignment constructor called" << std::endl;
	return *this;
}

Dog::Dog() : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << _type << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other.getBrain())) {
	std::cout << _type << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << _type << " destructor called" << std::endl;
}
