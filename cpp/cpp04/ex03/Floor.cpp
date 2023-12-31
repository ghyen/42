#include "Floor.hpp"

void Floor::takeTrash(AMateria *trash)
{
	int idx = 0;
	while (trashBin[idx])
		idx++;
	trashBin[idx] = trash;
}

Floor::Floor()
{
	for (int i = 0; i < 100; ++i)
	{
    	trashBin[i] = 0;
	}
	//std::cout << "Floor default constructor called" << std::endl;
}

Floor::Floor(const Floor& _ref)
{
	int i = 0;
	while (_ref.trashBin[i])
	{
		trashBin[i] = _ref.trashBin[i];
		i++;
	}
	//std::cout << "Floor copy constructor called" << std::endl;
}

Floor::~Floor()
{
	for (int i = 0; i < 100; ++i)
	{
    	delete trashBin[i];
    	trashBin[i] = nullptr;
	}
	//std::cout << "Floor " << " has destroyed" << std::endl;
}

Floor& Floor::operator=(const Floor& ref)
{
	int i = 0;
	while (ref.trashBin[i])
	{
		trashBin[i] = ref.trashBin[i];
		i++;
	}
	//std::cout << "Floor assignment operator called" << std::endl;
	return *this;
}

