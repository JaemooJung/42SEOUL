#include "WrongCat.hpp"

void WrongCat::makeSound() const {
	std::cout << _type << " is making sound: " << "WOEM" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		_type = other.getType();
	}
	std::cout << _type << " copy assignment constructor called" << std::endl;
	return *this;
}

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << _type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << _type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << _type << " destructor called" << std::endl;
}
