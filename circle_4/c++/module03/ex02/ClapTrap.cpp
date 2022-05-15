#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target) {
	if (_hitPoint == 0) {
		std::cout << "Attack failed." << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (_energyPoint == 0) {
		std::cout << "Attack failed." << "ClapTrap " << _name << " is out of energy." << std::endl;
		return;
	}
	_energyPoint -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << "." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoint == 0) {
		std::cout << "Take damage failed." << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (_hitPoint <= amount) {
		_hitPoint = 0;
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		return;
	}
	_hitPoint -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoint == 0) {
		std::cout << "Repaired failed." << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (_energyPoint == 0) {
		std::cout << "Repaired failed." << "ClapTrap " << _name << " is out of energy." << std::endl;
		return;
	}
	if (_hitPoint + amount > C_HITPOINT) {
		_hitPoint = C_HITPOINT;
	} else {
		_hitPoint += amount;
	}
	std::cout << "ClapTrap " << _name << " is repaired." << std::endl;
	std::cout << "Current HP: " << _hitPoint << std::endl;
}
void ClapTrap::printStatus() const {
	std::cout << std::left << std::setw(40) << std::setfill('=') << "Status of [" + _name + "] " << std::endl;
	std::cout << "HitPoint: " << _hitPoint << std::endl;
	std::cout << "EnergyPoint: " << _energyPoint << std::endl;
	std::cout << "AttackDamage: " << _attackDamage << std::endl;
	std::cout << std::setw(40) << std::setfill('=') << "=" << std::endl;
}

std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHitPoint() const {
	return _hitPoint;
}

unsigned int ClapTrap::getEnergyPoint() const {
	return _energyPoint;
}
unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void ClapTrap::setName(const std::string& name) {
	_name = name;
}

void ClapTrap::setHitPoint(unsigned int hitPoint) {
	_hitPoint = hitPoint;
}

void ClapTrap::setEnergyPoint(unsigned int energyPoint) {
	_energyPoint = energyPoint;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	_attackDamage = attackDamage;
}

ClapTrap::ClapTrap() {
	_name = "";
	_hitPoint = C_HITPOINT;
	_energyPoint = C_ENERGYPOINT;
	_attackDamage = C_ATTACKDAMAGE;
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) {
	_name = name;
	_hitPoint = C_HITPOINT;
	_energyPoint = C_ENERGYPOINT;
	_attackDamage = C_ATTACKDAMAGE;
	std::cout << "ClapTrap constructor with name [" << name <<  "] called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other.getName();
	_hitPoint = other.getHitPoint();
	_energyPoint = other.getEnergyPoint();
	_attackDamage = other.getAttackDamage();
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_hitPoint = other.getHitPoint();
		_energyPoint = other.getEnergyPoint();
		_attackDamage = other.getAttackDamage();
	}
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called." << std::endl;
}