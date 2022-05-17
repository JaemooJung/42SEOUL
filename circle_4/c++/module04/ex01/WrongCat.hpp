#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		void makeSound() const;
	
		WrongCat& operator=(const WrongCat& other);
		WrongCat();
		WrongCat(const WrongCat& other);
		virtual ~WrongCat();
};
