#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "hey, let's highfive dude" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string _name) : ClapTrap(_name, 100, 100, 30)
{
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& _FragTrap) : ClapTrap(_FragTrap.name, _FragTrap.hitPoints, _FragTrap.energyPoints, _FragTrap.attackDamage)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	return *this;
}
