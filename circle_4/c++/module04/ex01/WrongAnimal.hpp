#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	
	public:
		std::string getType() const;
		void setType(std::string type);
		virtual void makeSound() const;

		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
};

#endif // __WRONGANIMAL_H__