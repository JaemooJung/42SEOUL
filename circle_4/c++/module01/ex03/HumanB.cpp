#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	weapon = 0;
}

HumanB::HumanB(std::string name, Weapon weapon) {
	this->name = name;
	this->weapon = &weapon;
}

void	HumanB::attack(void) {
	if (weapon == 0 || weapon->getType().length() == 0)
		std::cout << this->name << " is unarmed." << std::endl;
	else
		std::cout << this->name << " attacks with " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

HumanB::~HumanB() {

}