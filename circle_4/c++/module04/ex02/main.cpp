#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Cat* cat = new Cat();
	Cat* cat2 = new Cat(*cat);

	//Animal* someAnimal = new Animal();

	cat->getBrain()->setIdea(0, "WOW");
	std::cout << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << cat2->getBrain()->getIdea(0) << std::endl;
	cat2->getBrain()->setIdea(1, "WHERE AM I?");
	std::cout << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << cat2->getBrain()->getIdea(1) << std::endl;
	
	i->makeSound();
	j->makeSound();
	cat->makeSound();
	cat2->makeSound();
	//someAnimal->makeSound();

	delete j;
	delete i;
	delete cat;
	delete cat2;
	return ;
}

int main() {
	std::cout << "===============Copy Test===============" << std::endl;
	test();	
	system("leaks animal | grep leaked");
	return 0;
}