#include "Zombie.hpp"

int main(void) {
	Zombie* zombieHorde = Zombie::zombieHorde(5, "jaemjung");

	for (int i = 0; i < 5; i++) {
		zombieHorde[i].announce();
	}
	delete[] zombieHorde;
	return (0);
}