#include "WrongAnimal.hpp"

std::string WrongAnimal::getType( void ) const
{
    return type;
}

WrongAnimal::WrongAnimal() : type("default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& _ref)
{
    type = _ref.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << " has destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "?" << std::endl;
}
