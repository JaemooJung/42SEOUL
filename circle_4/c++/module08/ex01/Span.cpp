#include "Span.hpp"

Span::Span() {
	
}

const char* Span::StoreFullException::what() const throw() {
	return "Error: cannot add number to span ; span is full";
}

const char* Span::NoSpanException::what() const throw() {
	return "Error: cannot find span";
}

const std::multiset<int>& Span::getData() const {
	return _data;
}

void Span::addNumber(int n) {
	if (_data.size() == _capacity) {
		throw StoreFullException();
	}
	_data.insert(n);
}

int Span::shortestSpan() const {
	if (_data.size() < 2) {
		throw NoSpanException();
	}
	std::multiset<int>::iterator it = _data.begin();
	std::multiset<int>::iterator next = ++it;
	std::set<int> sub;
	for(; next != _data.end(); ++it, ++next) {
		sub.insert(*next - *it);
	}
	return *sub.begin();
}

int Span::longestSpan() const {
	if (_data.size() < 2) {
		throw NoSpanException();
	}
	return *--_data.end() - *_data.begin();
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_data.clear();
		_data = other.getData();
		_capacity = other._capacity;
	}
	return *this;
}

Span::Span(unsigned int n) : _capacity(n) {
	
}

Span::Span(const Span& other) : _capacity(other._capacity) {
	_data.clear();
	_data = other.getData();
}

Span::~Span() {
	_data.clear();
}
