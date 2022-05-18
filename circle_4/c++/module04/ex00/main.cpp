#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	Cat* c = new Cat();
	Cat* d = new Cat(*c);

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* meta_w = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	WrongCat wrongCat;
	
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	wrongCat.makeSound();
	meta_w->makeSound();
	
	delete meta;
	delete j;
	delete i;
	delete c;
	delete d;
	delete meta_w;
	delete k;
}

int main() {
	test();
	system("leaks animal | grep leaked");
	return 0;
}