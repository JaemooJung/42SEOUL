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
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExecute;
	
	public:
		std::string getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExcuteGrade() const;
		void beSigned(const Bureaucrat& bc);
		
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
	
		Form& operator=(const Form& other);

		Form(std::string name, int gradeSign, int gradeExecute);
		Form(const Form& other);
		~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // __FORM_H__