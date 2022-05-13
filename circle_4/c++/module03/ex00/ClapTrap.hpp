#ifndef _CLAP_TRAP_HPP_
#define _CLAP_TRAP_HPP_

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoint = 10;
		int _energyPoint = 10;
		int _attackDamage = 0;

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif