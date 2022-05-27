#include "MutantStack.hpp"
#include <list>

void testOnSubject() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); 
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack); 
}

void testOnSubjectWithList() {
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3); 
	list.push_back(5); 
	list.push_back(737); //[...] mstack.push(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it; 
	} 
}

void test() {
	MutantStack<int> mstack;

	for (int i = 0; i < 10; i++) {
		mstack.push(i);
	}

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
		std::cout << *it << std::endl;
		*it = *it + 100;
	}

	for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); it++) {
		std::cout << *it << std::endl;
		//*it = *it + 100;
	}
	std::cout << "copied one" << std::endl;
	MutantStack<int> mstack2(mstack);
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++) {
		std::cout << *it << std::endl;
		*it = *it + 100;
	}
	std::cout << "copied one after adding" << std::endl;
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << "original" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void reverseTest() {
	MutantStack<double> mstack;

	std::cout << "reverse iterator test" << std::endl;
	for (int i = 0; i < 10; i++) {
		mstack.push(i);
	}

	for (MutantStack<double>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++) {
		std::cout << *it << std::endl;
		*it = *it + 100;
	}

	for (MutantStack<double>::const_reverse_iterator it = mstack.crbegin(); it != mstack.crend(); it++) {
		std::cout << *it << std::endl;
		*it = *it + 100;
	}
}

int main() {
	testOnSubject();
	std::cout << std::endl;
	testOnSubjectWithList();
	std::cout << std::endl;
	test();
	reverseTest();
	std::system("leaks mutantStack");
}