#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string type) : type(type) {

}

void	Weapon::setType(std::string type) {
	this->type = type;
}

const std::string&	Weapon::getType() const {
	const std::string& typeRef = this->type;

	return (typeRef);
}

Weapon::~Weapon() {

}