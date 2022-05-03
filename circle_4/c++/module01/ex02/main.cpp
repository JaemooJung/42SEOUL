#include <string>
#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "address of str\t\t\t: " << &str << std::endl;
	std::cout << "address held by stringPTR\t: " << strPTR << std::endl;
	std::cout << "address held by stringREF\t: " << &strREF << std::endl;
	std::cout << "string\t\t: " << str << std::endl;
	std::cout << "By strPTR\t: " << *strPTR << std::endl;
	std::cout << "By strREF\t: " << strREF << std::endl;
	return (0);
}