#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	checkExecutability(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		Form::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: Form("PresidentialPardonForm", target, _ppSignGrade, _ppExecGrade) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other) {

}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}
