#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain* _brain;

	public:
		void makeSound() const;
		Brain* getBrain() const;
	
		Cat& operator=(const Cat& other);
		Cat();
		Cat(const Cat& other);
		~Cat();
};

#endif // __CAT_H__