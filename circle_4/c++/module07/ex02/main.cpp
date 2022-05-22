#include "Array.hpp"

void test() {
	Array<int> a(10);
	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}
	std::cout << a << std::endl;
	try {
		std::cout << a[10] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Array<int> b(a);
	std::cout << b << std::endl;
	for (int i = 0; i < 10; i++) {
		b[i] = i + 10;
	}
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a = b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	Array<int> zero(0);
	std::cout << zero << std::endl;

	Array<std::string> stra(10);
	for (int i = 0; i < stra.size(); i++) {
		stra[i] = "Hello " + std::to_string(i);
	}
	std::cout << stra << std::endl;
}

int main() {
	test();
	system("leaks a.out");
	return 0;
}