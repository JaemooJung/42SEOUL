#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target) {
	if (_hitPoint == 0) {
	std::cout << "Attack failed." << "ScavTrap " << _name << " is already dead." << std::endl;
	return;
	}
	if (_energyPoint == 0) {
		std::cout << "Attack failed." << "ScavTrap " << _name << " is out of energy." << std::endl;
		return;
	}
	_energyPoint -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target << "." << std::endl;
}

void ScavTrap::guardGate(void) const {
	std::cout << "ScavTrap " << _name << " is guarding the gate." << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap() {
	_hitPoint = S_HIT_POINT;
	_energyPoint = S_ENERGY_POINT;
	_attackDamage = S_ATTACK_DAMAGE;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoint = S_HIT_POINT;
	_energyPoint = S_ENERGY_POINT;
	_attackDamage = S_ATTACK_DAMAGE;
	std::cout << "ScavTrap constructor with name [" << _name << "] called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	_name = other.getName();
	_hitPoint = other.getHitPoint();
	_energyPoint = other.getEnergyPoint();
	_attackDamage = other.getAttackDamage();
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_hitPoint = other.getHitPoint();
		_energyPoint = other.getEnergyPoint();
		_attackDamage = other.getAttackDamage();
	}
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destructor called." << std::endl;
}