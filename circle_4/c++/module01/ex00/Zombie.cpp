#include "Zombie.hpp"

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : name("Zom Doe") {
	std::cout << "New zombie " << this->name << " has awaken." << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << "New zombie " << this->name << " has awaken." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " has fallen." << std::endl;
}
