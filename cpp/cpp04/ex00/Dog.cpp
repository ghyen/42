#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& _ref)
{
	this->type = _ref.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog " << " has destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Dog assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "멍멍" << std::endl;
}
