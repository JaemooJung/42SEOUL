#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <cmath>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
//#include <sstream>
#include <stdexcept>
#include <iomanip>

class Converter {
	private:
		bool _isError;
		std::string _input;
		double _value;
		Converter();
	
	public:
		char toChar() const;
		int toInt() const;
		float toFloat() const;
		double toDouble() const;

		void printChar(std::ostream &os) const;
		void printInt(std::ostream &os) const;
		void printFloat(std::ostream &os) const;
		void printDouble(std::ostream &os) const;

		bool isError() const;
		std::string getInput() const;
		double getValue() const;

		Converter& operator=(const Converter& other);
		explicit Converter(std::string input);
		Converter(const Converter& other);
		~Converter();
};

std::ostream& operator<<(std::ostream& os, const Converter& converter);

#endif // __CONVERTER_H__