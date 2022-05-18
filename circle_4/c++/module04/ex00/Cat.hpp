#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal {
	public:
		void makeSound() const;
	
		Cat& operator=(const Cat& other);
		Cat();
		Cat(const Cat& other);
		~Cat();
};

#endif // __CAT_H__