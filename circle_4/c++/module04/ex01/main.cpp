#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test() {

}

int main() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	Cat *a = new Cat();
	Dog *b = new Dog();
	
	a->getBrain()->setIdea(0, "HELLO");
	Cat *c = new Cat(*a);
	std::cout << c->getBrain()->getIdea(0) << std::endl;
	c->getBrain()->setIdea(1, "Wahtthe");
	std::cout << a->getBrain()->getIdea(1) << std::endl;
	delete a;
	delete b;


	delete j;//should not create a leak
	delete i;

	system("leaks animal");
	return 0;
}