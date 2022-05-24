#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		Form();
		const std::string _name;
		const int _gradeSign;
		const int _gradeExecute;
		std::string _target;
		bool _isSigned;
	
	public:
		std::string getName() const;
		std::string getTarget() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat& bc);
		void checkExecutability(const Bureaucrat& executor) const;

		virtual void execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
	
		Form& operator=(const Form& other);
		Form(std::string name, std::string target, int gradeSign, int gradeExecute);
		Form(const Form& other);
		virtual ~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // __FORM_H__