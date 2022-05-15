#ifndef _FRAG_TRAP_HPP_
#define _FRAG_TRAP_HPP_

#include "ClapTrap.hpp"

#define F_HIT_POINT 100
#define F_ENERGY_POINT 100
#define F_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap {
	public:
		void highFiveGuys(void) const;
	
		FragTrap(void);
		explicit FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap(void);
};

#endif