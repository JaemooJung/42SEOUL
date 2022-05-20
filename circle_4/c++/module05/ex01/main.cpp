#include "Form.hpp"

int main() {
	Bureaucrat jaemjung("jaemjung", 10);
	Form sellAPPL("sellAPPL", 9, 9);

	try {
		Form buyAPPL("buyAPPL", 151, 1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form holdAPPL("holdAPPL", -1, 150);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << jaemjung << std::endl;
	std::cout << sellAPPL << std::endl;

	jaemjung.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;
	try {
		jaemjung.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jaemjung << std::endl;
	jaemjung.signForm(sellAPPL);
	std::cout << sellAPPL << std::endl;
}