#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* meta_w = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	meta_w->makeSound();
	return 0;
}