#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal {
	public:
		void makeSound() const;

		Dog& operator=(const Dog& other);
		Dog();
		Dog(const Dog& other);
		virtual ~Dog();
};

#endif // __DOG_H__