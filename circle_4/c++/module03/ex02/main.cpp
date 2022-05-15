#include "FragTrap.hpp"

int main(void) {
	FragTrap a("A");
	FragTrap b = a;

	b.setName("B");
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;
	
	a.highFiveGuys();
}