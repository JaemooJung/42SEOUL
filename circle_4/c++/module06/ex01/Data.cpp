#include "Data.hpp"

std::string Data::getDoomName() const {
	return _doomName;
}

int Data::getDayLeft() const {
	return _dayLeft;
}

bool Data::isDoomed() const {
	return _isDoomed;
}

float Data::getDoomFactor() const {
	return _doomFactor;
}

double Data::getDoomDuration() const {
	return _doomDuration;
}

void Data::setDoomName(std::string doomName) {
	_doomName = doomName;
}

void Data::setDayLeft(int dayLeft) {
	_dayLeft = dayLeft;
}

void Data::setDoomed(bool isDoomed) {
	_isDoomed = isDoomed;
}

void Data::setDoomFactor(float doomFactor) {
	_doomFactor = doomFactor;
}

void Data::setDoomDuration(double doomDuration) {
	_doomDuration = doomDuration;
}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		_doomName = other.getDoomName();
		_dayLeft = other.getDayLeft();
		_isDoomed = other.isDoomed();
		_doomFactor = other.getDoomFactor();
		_doomDuration = other.getDoomDuration();
	}
	return *this;
}

Data::Data() {
	
}

Data::Data(std::string doomName, int dayLeft, bool isDoomed, float doomFactor, double doomDuration)
: _doomName(doomName), 
_dayLeft(dayLeft), 
_isDoomed(isDoomed), 
_doomFactor(doomFactor), 
_doomDuration(doomDuration) {
	
}

Data::Data(const Data& other)
: _doomName(other.getDoomName()),
_dayLeft(other.getDayLeft()),
_isDoomed(other.isDoomed()),
_doomFactor(other.getDoomFactor()),
_doomDuration(other.getDoomDuration()) {
	
}

Data::~Data() {
	
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
	return os << "Data address: " << &data << std::endl
			<< "Doom name: " << data.getDoomName() << std::endl
			<< "Day left: " << data.getDayLeft() << std::endl
			<< "Doom factor: " << data.getDoomFactor() << std::endl
			<< "Doom duration: " << data.getDoomDuration() << std::endl
			<< "Is doomed: " << data.isDoomed() << std::endl;
}
