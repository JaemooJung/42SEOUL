#include "Span.hpp"

void displaySpan(const std::string& str, const Span& span) {
	std::cout << str << std::endl;
	std::cout << "ShortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << span.longestSpan() << std::endl;
}

void basicTest() {
	std::cout << "Basic test----------------------" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	displaySpan("test on the subject", sp);

	Span sp2 = Span(sp);
	displaySpan("copy test", sp2);
	std::cout << "--------------------------------" << std::endl;
}

void errorTest() {
	std::cout << "error test----------------------" << std::endl;
	Span sp = Span(50);
	
	try {
		sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(0);
	try {
		sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(1);
	displaySpan("[0-1 test]", sp);
	for (int i = 2; i < 50; i++) {
		sp.addNumber(i);
	}
	try {
		sp.addNumber(100);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	displaySpan("[final result]", sp);
	std::cout << "--------------------------------" << std::endl;
}

void zeroTest() {
	std::cout << "zero test----------------------" << std::endl;
	Span sp = Span(2);
	
	sp.addNumber(0);
	sp.addNumber(0);
	displaySpan("[result]", sp);
	std::cout << "--------------------------------" << std::endl;
}

void largeTest() {
	Span sp = Span(100000);

	for (int i = 0; i < 99999; i++) {
		sp.addNumber(i);
	}
	sp.addNumber(100000);
	displaySpan("[Large test]", sp);
}

void rangeTest() {
	std::cout << "range test----------------------" << std::endl;
	Span sp = Span(5);

	int a[3] = {0, 10, 200};
	sp.addRange(std::begin(a), std::end(a));
	displaySpan("[range 3]", sp);

	try {
		sp.addNumber(3000);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	displaySpan("[add 10000]", sp);
	
	try {
		sp.addRange(std::begin(a), std::end(a));
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	int b[1] = {10000};
	try {
		sp.addRange(std::begin(b), std::end(b));
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	displaySpan("[result]", sp);
}

int main() {
	basicTest();
	errorTest();
	zeroTest();
	largeTest();
	rangeTest();
	std::system("leaks span | grep leaked");
}