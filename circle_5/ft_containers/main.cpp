#include <vector>
#include <iostream>
#include "Vector.hpp"

int main(void) {
	std::vector<int> v;
	ft::vector<int> myV;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);

	while (v.size() > 0) {
		std::cout << v.back() << std::endl;
		std::cout << v.size() << std::endl;
		v.pop_back();
	}
	std::cout << v.size() << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << v.capacity() << std::endl;

	std::cout << myV.max_size() << std::endl;
}