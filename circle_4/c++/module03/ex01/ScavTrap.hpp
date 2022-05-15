#ifndef _SCAV_TRAP_HPP_
#define _SCAV_TRAP_HPP_

#include "ClapTrap.hpp"

#define S_HIT_POINT 100
#define S_ENERGY_POINT 50
#define S_ATTACK_DAMAGE 20

class ScavTrap: public ClapTrap {
	public:
		void attack(const std::string& target);
		void guardGate(void) const;

		ScavTrap(void);
		explicit ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap(void);
};

#endif