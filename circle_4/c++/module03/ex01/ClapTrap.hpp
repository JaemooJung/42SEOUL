#ifndef _CLAP_TRAP_HPP_
#define _CLAP_TRAP_HPP_

#include <string>
#include <iostream>
#include <iomanip>

#define C_HITPOINT 10
#define C_ENERGYPOINT 10
#define C_ATTACKDAMAGE 0

class ClapTrap {
	protected:
		std::string _name;
		unsigned int _hitPoint;
		unsigned int _energyPoint;
		unsigned int _attackDamage;

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus() const;

		std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;

		void setName(const std::string& name);
		void setHitPoint(unsigned int hitPoint);
		void setEnergyPoint(unsigned int energyPoint);
		void setAttackDamage(unsigned int attackDamage);

		ClapTrap();
		explicit ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
};

#endif