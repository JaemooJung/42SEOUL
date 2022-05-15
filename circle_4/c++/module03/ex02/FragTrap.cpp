#include "FragTrap.hpp"

void FragTrap::highFiveGuys(void) const {
	std::cout << "FragTrap " << _name << " wants to high five everybody!" << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap() {
	_hitPoint = F_HIT_POINT;
	_energyPoint = F_ENERGY_POINT;
	_attackDamage = F_ATTACK_DAMAGE;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoint = F_HIT_POINT;
	_energyPoint = F_ENERGY_POINT;
	_attackDamage = F_ATTACK_DAMAGE;
	std::cout << "FragTrap constructor with name [" << _name << "] called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
	_name = other.getName();
	_hitPoint = other.getHitPoint();
	_energyPoint = other.getEnergyPoint();
	_attackDamage = other.getAttackDamage();
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_hitPoint = other.getHitPoint();
		_energyPoint = other.getEnergyPoint();
		_attackDamage = other.getAttackDamage();
	}
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " destructor called." << std::endl;
}