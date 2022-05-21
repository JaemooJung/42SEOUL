#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat jaemjung("jaemjung", 1);
	Form* shrubbery = new ShrubberyCreationForm("GAEPO");
	Form* robotomy = new RobotomyRequestForm("GEAPO");
	Form* pp = new PresidentialPardonForm("JAEMJUNG");

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