#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test() {
	Bureaucrat jaemjung("jaemjung", 150);
	Intern someIntern;

	Form* shrubbery = someIntern.makeForm("shrubbery creation", "GAEPO");
	Form* robotomy = someIntern.makeForm("robotomy request", "GEAPO");
	Form* pp = someIntern.makeForm("presidential pardon", "JAEMJUNG");
	someIntern.makeForm("makeMoney request", "JAEMJUNG");

	std::cout << jaemjung << std::endl;
	std::cout << std::endl;

	std::cout << *shrubbery << std::endl;
	jaemjung.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	jaemjung.executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << *robotomy << std::endl;
	jaemjung.signForm(*robotomy);
	std::cout << *robotomy << std::endl;
	jaemjung.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << *pp << std::endl;
	jaemjung.signForm(*pp);
	std::cout << *pp << std::endl;
	jaemjung.executeForm(*pp);
	std::cout << std::endl;

	delete shrubbery;
	delete robotomy;
	delete pp;
}

int main() {
	test();
	system("leaks form");
}