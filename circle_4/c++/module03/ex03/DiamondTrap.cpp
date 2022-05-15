#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI() const {
	std::cout << "I am a DiamondTrap named " << this->_name << "." << std::endl;
	std::cout << "And my grandma ClapTrap's name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName(void) const {
	return _name;
}

void DiamondTrap::printStatus(void) const {
	std::cout << std::left << std::setw(40) << std::setfill('=') << "Status of [" + _name + "] " << std::endl;
	std::cout << "HitPoint: " << _hitPoint << std::endl;
	std::cout << "EnergyPoint: " << _energyPoint << std::endl;
	std::cout << "AttackDamage: " << _attackDamage << std::endl;
	std::cout << std::setw(40) << std::setfill('=') << "=" << std::endl;
}

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name") {
	_name = "";
	_hitPoint = F_HIT_POINT;
	_energyPoint = S_ENERGY_POINT;
	_attackDamage = F_ATTACK_DAMAGE;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") {
	_name = name;
	_hitPoint = F_HIT_POINT;
	_energyPoint = S_ENERGY_POINT;
	_attackDamage = F_ATTACK_DAMAGE;
	std::cout << "DiamondTrap constructor with name [" << _name << "] called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	_name = other.getName();
	_hitPoint = other.getHitPoint();
	_energyPoint = other.getEnergyPoint();
	_attackDamage = other.getAttackDamage();
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_hitPoint = other.getHitPoint();
		_energyPoint = other.getEnergyPoint();
		_attackDamage = other.getAttackDamage();
	}
	std::cout << "DiamondTrap copy assignment operator called." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << _name << " destructor called." << std::endl;
}