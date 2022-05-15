#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap a("A");
	DiamondTrap b("B");
	DiamondTrap c = DiamondTrap();

	a.whoAmI();
	b.whoAmI();
	c.whoAmI();

	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;
	
	a.whoAmI();
	b.whoAmI();
}