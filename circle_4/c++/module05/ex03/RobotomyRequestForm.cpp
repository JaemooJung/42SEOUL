#include "RobotomyRequestForm.hpp"


void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkExecutability(executor);

	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	std::srand(static_cast<unsigned int>(time(NULL)));
	int rand = std::rand();
	if (rand % 2) {
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "failed to robotomize " << getTarget() << std::endl;
	}

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		Form::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: Form("RobotomyRequestForm", target, _rrSignGrade, _rrExecGrade) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other) {
	
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}
