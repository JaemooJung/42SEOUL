#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	int n = rand() % 3;
	switch (n) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* obj) {
	if (dynamic_cast<A*>(obj)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(obj)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(obj)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown" << std::endl;
	}
}

void identify(Base& obj) {
	try {
		(void)dynamic_cast<A&>(obj);
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<B&>(obj);
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<C&>(obj);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {
		(void)e;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	Base* testptr;

	std::cout << "=================pointer" << std::endl;
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;
	
	testptr = generate();
	identify(testptr);
	delete testptr;

	std::cout << "=================reference" << std::endl;
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;
	
	testptr = generate();
	identify(*testptr);
	delete testptr;

	return 0;
}