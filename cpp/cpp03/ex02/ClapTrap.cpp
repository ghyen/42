#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string _name, const unsigned int _hitPoints, const unsigned int _energyPoints, const unsigned int _attackDamage) : name(_name), hitPoints(_hitPoints), energyPoints(_energyPoints), attackDamage(_attackDamage)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
	: name(clapTrap.name), hitPoints(clapTrap.hitPoints), energyPoints(clapTrap.energyPoints), attackDamage(clapTrap.attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	name = clapTrap.name;
	hitPoints = clapTrap.hitPoints;
	energyPoints = clapTrap.energyPoints;
	attackDamage = clapTrap.attackDamage;
	return *this;
}

std::string ClapTrap::getName() const
{
	return name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int newAttackDamage)
{
	attackDamage = newAttackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (!hitPoints)
		std::cout << "ClapTrap " << name << " has no hit points left." << std::endl;
	else if (!energyPoints)
		std::cout << "ClapTrap " << name << " has no energy points left." << std::endl;
	else {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	if (hitPoints < amount)
		amount = hitPoints;
	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{	
	if (!hitPoints)
		std::cout << "ClapTrap " << name << " has no hit points left." << std::endl;
	else if (!energyPoints)
		std::cout << "ClapTrap " << name << " has no energy points left." << std::endl;
	else {
		std::cout << "ClapTrap " << name << " repaires " << amount << " points!" << std::endl;
		hitPoints += amount;
		energyPoints--;
	}
}
