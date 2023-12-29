#include "Floor.hpp"

void Floor::takeTrash(void *trash)
{
	int idx = 0;
	while (trashBin[idx])
		idx++;
	trashBin[idx] = trash;
}

Floor::Floor()
{
	std::cout << "Floor default constructor called" << std::endl;
}

Floor::Floor(const Floor& _ref)
{
	std::cout << "Floor copy constructor called" << std::endl;
}

Floor::~Floor()
{
	std::cout << "Floor " << " has destroyed" << std::endl;
}

Floor& Floor::operator=(const Floor& ref)
{
	std::cout << "Floor assignment operator called" << std::endl;
	return *this;
}

