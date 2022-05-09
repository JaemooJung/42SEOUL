#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB();
		~HumanB();
		HumanB(std::string name);
		HumanB(std::string name, Weapon weapon);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif
