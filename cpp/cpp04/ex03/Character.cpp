#include "Character.hpp"

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (inventory[i] == NULL)
			inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (!inventory[idx])
		{
			std::cout << "there's no item" << std::endl;
			return ;
		}
		floor.takeTrash(&inventory[idx]);
		inventory[idx] = NULL;
		return ;
	}
	std::cout << "idx should be 0 to 3" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
	{
		inventory[idx]->use(target);
		return ;
	}
	std::cout << "worng idx" << std::endl;
}

Character::Character() : name("")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string &_name) : name(_name)
{
	std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& _ref) : name(_ref.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
		
	std::cout << "Character " << " has destroyed" << std::endl;
}

Character& Character::operator=(const Character& ref)
{
	std::cout << "Character assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
			inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (ref.inventory[i] != NULL)
			inventory[i] = ref.inventory[i]->clone();
	}
	return *this;
}
