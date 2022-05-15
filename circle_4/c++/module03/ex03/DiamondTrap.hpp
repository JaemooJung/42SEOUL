#ifndef _DIAMOND_TRAP_HPP_
#define _DIAMOND_TRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;
	
	public:
		void whoAmI(void) const;
		void attack(const std::string& target);
		std::string getName(void) const;
		void printStatus(void) const;

		DiamondTrap(void);
		explicit DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap(void);
};

#endif