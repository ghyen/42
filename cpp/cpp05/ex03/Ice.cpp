#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->type = "ice";
	//std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& _ref)
{
	this->type = _ref.type;
	//std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice " << " has destroyed" << std::endl;
}

Ice& Ice::operator=(const Ice& ref)
{
	//std::cout << "Ice assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice();
}
