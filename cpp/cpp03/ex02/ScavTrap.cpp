#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
	std::cout << "you can not go throgh" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!hitPoints)
		std::cout << "ScavTrap " << name << " has no hit points left." << std::endl;
	else if (!energyPoints)
		std::cout << "ScavTrap " << name << " has no energy points left." << std::endl;
	else {
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name, 100, 50, 20)
{
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& _ScavTrap) : ClapTrap(_ScavTrap.name, _ScavTrap.hitPoints, _ScavTrap.energyPoints, _ScavTrap.attackDamage)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	return *this;
}
