#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << _type << " is making sound: " << "MEOW MEOW MEOW" << std::endl;
}

Brain* Cat::getBrain() const {
	return _brain;
}

void Cat::setBrain(Brain* const brain) {
	*_brain = *brain;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other.getType();
		this->setBrain(other.getBrain());
	}
	std::cout << _type << " copy assignment constructor called" << std::endl;
	return *this;
}

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << _type << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(), _brain(new Brain()) {
	_type = other.getType();
	this->setBrain(other.getBrain());
	std::cout << _type << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type << " destructor called" << std::endl;
	delete _brain;
}
