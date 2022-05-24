#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		Bureaucrat();
		const std::string _name;
		int _grade;

	public:
		std::string getName() const;
		int getGrade() const;
		void signForm(Form& form) const;
		void executeForm(Form& form) const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // __BUREAUCRAT_H__