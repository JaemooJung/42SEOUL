#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string Contact::getSecret() const
{
	return (this->secret);
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

void Contact::showInfo(void) const
{
	std::cout << std::setw(17) << "First Name: " << getFirstName() << std::endl;
	std::cout << std::setw(17) << "Last Name: " << getLastName() << std::endl;
	std::cout << std::setw(17) << "Nickname: " << getNickname() << std::endl;
	std::cout << std::setw(17) << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << std::setw(17) << "Darkest Secret: " << getSecret() << std::endl;
}

Contact::Contact() {

}

Contact::~Contact() {

}