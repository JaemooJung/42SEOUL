#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	
	public:
		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const = 0;

		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
};

#endif // __ANIMAL_H__