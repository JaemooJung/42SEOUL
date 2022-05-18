#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain* _brain;

	public:
		void makeSound() const;
		Brain *getBrain() const;
		void setBrain(Brain* const brain);

		Dog& operator=(const Dog& other);
		Dog();
		Dog(const Dog& other);
		virtual ~Dog();
};

#endif // __DOG_H__