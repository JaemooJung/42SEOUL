#include "Bureaucrat.hpp"

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << _name << " couldn't sign " << form.getName() 
					<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) {
		throw GradeTooHighException();
	}
	_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		throw GradeTooLowException();
	}
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "This Bureaucrat's grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "This Bureaucrat's grade is too low!";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		*(const_cast<std::string*>(&_name)) = other.getName();
		_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat() {
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade > 150) {
		throw GradeTooLowException();
	} else if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade()) {
	
}

Bureaucrat::~Bureaucrat() {
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	return os << b.getName() << ", " << "bureaucrat grade " << b.getGrade() << ".";
}
