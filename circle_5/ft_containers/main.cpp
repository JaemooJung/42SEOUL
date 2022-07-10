#include <vector>
#include <iostream>
#include <iterator>
#include "Vector.hpp"

int main(void) {
	std::vector<int> v;
	ft::vector<int> myV;
	std::cout << "===========================================================" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << myV.size() << std::endl;
	std::cout << myV.max_size() << std::endl;
	std::cout << myV.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;

	v.push_back(1);
	myV.push_back(1);
	v.push_back(2);
	myV.push_back(2);
	v.push_back(3);
	myV.push_back(3);
	std::cout << "========================push test==========================" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << myV.size() << std::endl;
	std::cout << myV.max_size() << std::endl;
	std::cout << myV.capacity() << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "========================iterator test======================" << std::endl;
	std::cout << "v.begin() = " << *v.begin() << std::endl;
	std::cout << "v.end() - 1 = " << *(v.end() - 1) << std::endl;
	std::cout << "myV.begin() = " << *myV.begin() << std::endl;
	std::cout << "myV.end() - 1 = " << *(myV.end() - 1) << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "========================reverse iterator test================" << std::endl;
	std::cout << "v.rbegin() = " << *v.rbegin() << std::endl;
	std::cout << "v.rend() - 1 = " << *(v.rend() - 1) << std::endl;
	std::cout << "myV.rbegin() = " << *myV.rbegin() << std::endl;
	std::cout << "myV.rend() - 1 = " << *(myV.rend() - 1) << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::reverse_iterator it = myV.rbegin(); it != myV.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "=========================pop test========================" << std::endl;
	v.pop_back();
	myV.pop_back();
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;

	std::cout << "=========================resize test======================" << std::endl;
	v.resize(10);
	myV.resize(10);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "==========================================================" << std::endl;

	std::cout << "=========================reserve test========================" << std::endl;
	v.reserve(100);
	myV.reserve(100);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "myV.capacity() = " << myV.capacity() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;


	std::cout << "=========================insert test========================" << std::endl;
	v.insert(v.begin() + 9, 12);
	myV.insert(myV.begin() + 9, 12);
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "myV.size() = " << myV.size() << std::endl;
	std::cout << "=========================iteration=========================" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = myV.begin(); it != myV.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;
}