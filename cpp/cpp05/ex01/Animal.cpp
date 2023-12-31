#include "Animal.hpp"

std::string Animal::getType( void ) const
{
    return type;
}

Animal::Animal() : type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& _ref)
{
    type = _ref.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << " has destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal& ref)
{
	std::cout << "Animal assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}
