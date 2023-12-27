#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	this->type = "WrongDog";
	std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& _ref)
{
	this->type = _ref.type;
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog " << " has destroyed" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& ref)
{
	std::cout << "WrongDog assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void WrongDog::makeSound(void) const
{
	std::cout << "멍멍" << std::endl;
}
