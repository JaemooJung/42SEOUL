#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		PresidentialPardonForm();
		static const int _ppSignGrade = 25;
		static const int _ppExecGrade = 5;

	public:
		void execute(const Bureaucrat& executor) const;

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
};

#endif // __PRESIDENTIALPARDONFORM_H__