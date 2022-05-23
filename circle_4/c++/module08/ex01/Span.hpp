#ifndef __SPAN_H__
#define __SPAN_H__

#include <set>
#include <exception>
#include <iostream>

class Span {
	private:
		std::multiset<int> _data;
		unsigned int _capacity;
		Span();
		
	public:
	class StoreFullException: public std::exception {
		public:
			const char* what() const throw();
	};

	class NoSpanException: public std::exception {
		public:
			const char* what() const throw();
	};

	const std::multiset<int>& getData() const;

	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;

	Span& operator=(const Span& other);
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

};

#endif // __SPAN_H__