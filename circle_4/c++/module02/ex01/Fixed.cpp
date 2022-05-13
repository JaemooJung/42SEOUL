#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = i << _fractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(f * (1 << _fractionalBits));
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
	return (_fixedPointValue);
}

void Fixed::setRawBits(int value) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = value;
}

int Fixed::toInt() const {
	return (_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat() const {
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed &ref) {
	os << ref.toFloat();
	return (os);
}
