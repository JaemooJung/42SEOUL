#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int currentIndex;
		std::string receiveUserInput(std::string message);
		void printPhoneBook();
		std::string cutOver10(std::string str);
	public:
		void addContact();
		void searchIndex();
		PhoneBook();
		~PhoneBook();
};

#endif