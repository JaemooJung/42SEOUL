#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a("A");
	ClapTrap b = a;

	b.setName("B");

	a.setAttackDamage(5);
	b.setAttackDamage(10);
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		b.attack("A");
		a.takeDamage(b.getAttackDamage());
	}
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.beRepaired(1);
	b.beRepaired(1);

	a = b;
	a.printStatus();
}