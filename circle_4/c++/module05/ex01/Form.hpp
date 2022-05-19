#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExcute;
	
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
	
};

#endif // __FORM_H__