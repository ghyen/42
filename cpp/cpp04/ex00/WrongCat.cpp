#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& _ref)
{
	this->type = _ref.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << " has destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "냐옹" << std::endl;
}
