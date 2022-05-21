#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	checkExecutability(executor);

	std::ofstream output(this->getTarget() + "_shrubbery");
	std::ifstream input("shrubbery");
	std::string line;

	if (!output.good() || !input.good()) {
		throw ShrubberyCreationForm::FailToOpenFileException();
	}
	while (!input.eof()) {
		getline(input, line);
		output << line << std::endl;
	}
	input.close();
	output.close();
}

const char* ShrubberyCreationForm::FailToOpenFileException::what() const throw() {
	return "Failed to open file";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		Form::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", target, _scSignGrade, _scExecGrade) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
: Form(other) {
	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}
