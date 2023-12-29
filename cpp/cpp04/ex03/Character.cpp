#include "Character.hpp"

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	int idx = 0;

	while (inventory[idx] || idx < 4)
		idx++;
	if (idx)
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 4)
	{
		if (!inventory[idx])
		{
			std::cout << "there's no item" << std::endl;
			return ;
		}
		floor.takeTrash(&inventory[idx]);
		return ;
	}
	std::cout << "idx should be 0 to 3" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	
}

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	floor = new Floor();
}

Character::Character(std::string &_name)
{
	name = _name;
	std::cout << "Character name constructor called" << std::endl;
}

Character::Character(const Character& _ref)
{
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character " << " has destroyed" << std::endl;
}

Character& Character::operator=(const Character& ref)
{
	std::cout << "Character assignment operator called" << std::endl;
	for (unsigned long i = 0; i < ideas->length(); i++)
		ideas[i] = ref.ideas[i];
	return *this;
}
