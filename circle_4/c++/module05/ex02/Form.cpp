#include "Form.hpp"

std::string Form::getName() const {
	return _name;
}

std::string Form::getTarget() const {
	return _target;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _gradeSign;
}

int Form::getExecuteGrade() const {
	return _gradeExecute;
}

void Form::beSigned(const Bureaucrat& bc) {
	if (bc.getGrade() <= _gradeSign) {
		_isSigned = true;
	}
	else {
		throw Form::GradeTooHighException();
	}
}

void Form::checkExecutability(const Bureaucrat& executor) const {
	if (!_isSigned) {
		throw Form::FormNotSignedException();
	} else if (executor.getGrade() > _gradeExecute) {
		throw Form::GradeTooHighException();
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade of this form is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade of this form is too low";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "This form is not signed";
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		*(const_cast<std::string*>(&_name)) = other.getName();
		*(const_cast<int*>(&_gradeSign)) = other.getSignGrade();
		*(const_cast<int*>(&_gradeExecute)) = other.getExecuteGrade();
		_isSigned = other.isSigned();
		_target = other.getTarget();
	}
	return *this;
}

Form::Form()
: _name(""),
_gradeSign(150),
_gradeExecute(150),
_target("") {
	
}

Form::Form(std::string name, std::string target, int gradeSign, int gradeExecute) 
: _name(name),
_gradeSign(gradeSign), 
_gradeExecute(gradeExecute),
_target(target) {
	if (_gradeSign < 1 || _gradeExecute < 1) {
		throw Form::GradeTooHighException();
	}
	else if (_gradeSign > 150 || _gradeExecute > 150) {
		throw Form::GradeTooLowException();
	}
}
	
Form::Form(const Form& other)
: _name(other.getName()),
_gradeSign(other.getSignGrade()),
_gradeExecute(other.getExecuteGrade()),
_target(other.getTarget()) {
	_isSigned = other.isSigned();
}

Form::~Form() {
	
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	return (os	<< form.getName() << " is " 
				<< (form.isSigned() ? "SIGNED" : "not signed")
				<< " and grade of " << form.getSignGrade() << " is required to be sigend" 
				<< " and " << form.getExecuteGrade() << " is required to be executed"
			);
}
