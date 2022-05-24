#include "Converter.hpp"

Converter::Converter() {
	
}

char Converter::toChar() const {
	return static_cast<char>(_value);
}

int Converter::toInt() const {
	return static_cast<int>(_value);
}

float Converter::toFloat() const {
	return static_cast<float>(_value);
}

double Converter::toDouble() const {
	return static_cast<double>(_value);
}

void Converter::printChar(std::ostream &os) const {
	os << "char: ";
	if (_value != _value || _value > std::numeric_limits<char>::max() || _value < std::numeric_limits<char>::min()) {
		os << "impossible" << std::endl;
	} else if (std::isprint(toChar())) {
		os << "'" << toChar() << "'" << std::endl;
	} else {
		os << "non displayable" << std::endl;
	}
}

void Converter::printInt(std::ostream &os) const {
	os << "int: ";
	if (_value != _value || _value > std::numeric_limits<int>::max() || _value < std::numeric_limits<int>::min()) {
		os << "impossible" << std::endl;
	} else {
		os << toInt() << std::endl;
	}
}

void Converter::printFloat(std::ostream &os) const {
	if (toFloat() == static_cast<int64_t>(toFloat())) {
		os << "float: " << toFloat() << ".0f" << std::endl;
	} else {
		os << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << toFloat() << "f" << std::endl;
	}
}

void Converter::printDouble(std::ostream &os) const {
	if (toDouble() == static_cast<int64_t>(toDouble())) {
		os << "double: " << toDouble() << ".0" << std::endl;
	} else {
		os << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << toDouble() << std::endl;
	}
}

bool Converter::isError() const {
	return _isError;
}

std::string Converter::getInput() const {
	return _input;
}

double Converter::getValue() const {
	return _value;
}

Converter& Converter::operator=(const Converter& other) {
	if (this != &other) {
		_isError = other.isError();
		_input = other.getInput();
		_value = other.getValue();
	}
	return *this;
}

Converter::Converter(std::string input) 
: _isError(false), _input(input), _value(0.0) {
	try {
		char *ptr = NULL;
		_value = std::strtod(_input.c_str(), &ptr);
		if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0]))) {
			throw std::bad_alloc();
		}
		if (*ptr && std::strcmp(ptr, "f"))
			throw std::bad_alloc();
	} catch (std::exception& ) {
		_isError = true;
	}
}

Converter::Converter(const Converter& other)
: _isError(other._isError), _input(other._input), _value(other._value) {
	
}

Converter::~Converter() {
	
}

std::ostream& operator<<(std::ostream& os, const Converter& converter) {
	if (converter.isError()) {
		os << "Conversion failed" << std::endl;
		return os;
	}
	converter.printChar(os);
	converter.printInt(os);
	converter.printFloat(os);
	converter.printDouble(os);
	return os;
}