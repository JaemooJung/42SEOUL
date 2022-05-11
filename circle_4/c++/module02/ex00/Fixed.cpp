#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int value) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = value;
}

