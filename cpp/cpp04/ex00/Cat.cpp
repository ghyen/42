#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& _ref)
{
	this->type = _ref.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat " << " has destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "냐옹" << std::endl;
}
