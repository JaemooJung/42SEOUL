#include "Zombie.hpp"

int main(void) {
	Zombie zombie1("jaemjung");
	Zombie *zombie2 = Zombie::newZombie("jaemjungOnHeap");

	zombie1.announce();
	zombie2->announce();
	Zombie::randomChump("jaemjungOnStack");
	delete zombie2;
}