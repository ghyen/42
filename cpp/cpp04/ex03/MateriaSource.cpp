#include "MateriaSource.hpp"

void learnMateria(AMateria*)
{
	
}

AMateria* createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (mSlot[i] != NULL && mSlot[i].getType == type)
		{
			return mSlot[i]->clone();
		}
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		mSlot[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& _ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (mSlot[i] != NULL)
			delete mSlot[i];
		if (_ref.mSlot[i])
			mSlot[i] = _ref.mSlot[i]->clone();
		else
			mSlot[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete mSlot[i];
	std::cout << "MateriaSource " << " has destroyed" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (mSlot[i] != NULL)
			delete mSlot[i];
		if (ref.mSlot[i])
			mSlot[i] = ref.mSlot[i]->clone();
		else
			mSlot[i] = NULL;
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return *this;
}
