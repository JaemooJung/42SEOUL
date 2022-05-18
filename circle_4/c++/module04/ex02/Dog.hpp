#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain* _brain;

	public:
		void makeSound() const;
		Brain* getBrain() const;
		
		Dog& operator=(const Dog& other);
		Dog();
		Dog(const Dog& other);
		~Dog();
};

#endif // __DOG_H__