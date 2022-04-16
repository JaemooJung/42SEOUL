#include "Zombie.hpp"

int main(void) {
	Zombie zombie1("jaemjung");
	Zombie *zombie2 = Zombie::newZombie("jaemjung");

	zombie1.announce();
	zombie2->announce();
	Zombie::randomChump("jaemjungOnStack");
}