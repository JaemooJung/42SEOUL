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

	class OutOfRangeException: public std::exception {
		public:
			const char* what() const throw();
	};

	const std::multiset<int>& getData() const;

	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename T>
	void addRange(T begin, T end) {
		if ( static_cast<unsigned int>(std::distance(begin, end)) > (_capacity - _data.size())) {
			throw OutOfRangeException();
		}
		for (; begin != end; ++begin) {
			addNumber(*begin);
		}
	}

	Span& operator=(const Span& other);
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

};

#endif // __SPAN_H__