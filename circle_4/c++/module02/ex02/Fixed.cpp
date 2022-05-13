#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPointValue = 0;
}

Fixed::Fixed(const int i) {
	_fixedPointValue = i << _fractionalBits;
}

Fixed::Fixed(const float f) {
	_fixedPointValue = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	if (*this != ref)
		_fixedPointValue = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
}

bool Fixed::operator==(const Fixed &other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->getRawBits() != other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) const {
	return this->getRawBits() > other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) {
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& other) {
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& other) {
	Fixed result(this->toFloat() * other.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed& other) {
	Fixed result(this->toFloat() / other.toFloat());
	return result;
}

Fixed& Fixed::operator++() {
	++_fixedPointValue;
	return (*this);
}

Fixed& Fixed::operator--() {
	--_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed result(*this);
	
	operator++();
	return result;
}

Fixed Fixed::operator--(int) {
	Fixed result(*this);

	operator--();
	return result;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a > b)
		return b;
	return a;	
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a > b)
		return b;
	return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}

int Fixed::getRawBits() const {
	return (_fixedPointValue);
}

void Fixed::setRawBits(int value) {
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
