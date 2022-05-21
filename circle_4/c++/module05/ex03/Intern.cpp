#include "Intern.hpp"

Form* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	try {
		for (int i = 0; i < 3; i++) {
			if (formName == formNames[i]) {
				std::cout << "Intern creates " << formNames[i] << " form" << std::endl;
				switch (i) {
					case 0:
						return new RobotomyRequestForm(target);
					case 1:
						return new ShrubberyCreationForm(target);
					case 2:
						return new PresidentialPardonForm(target);
				}
			}
		}
		throw Intern::CannotFindMatchingFormException();
	} catch (Intern::CannotFindMatchingFormException& e) {
		std::cout << "Intern failed to create form because " << e.what() << std::endl;
	}
	return NULL;
}


const char* Intern::CannotFindMatchingFormException::what() const throw() {
	return "Ahh... I think I can't find a matching form... sorry...";
}

Intern& Intern::operator=(const Intern& other) {
	static_cast<void>(other);
	return *this;
}

Intern::Intern() {
	
}

Intern::Intern(const Intern& other) {
	static_cast<void>(other);
}

Intern::~Intern() {
	
}
