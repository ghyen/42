#include "Amateria.hpp"

std::string const Amateria::&getType( void ) const
{
    return type;
}

AMateria::AMateria(std::string const &type)
{
	this.type = type;
}

Amateria::Amateria() : type("default")
{
	std::cout << "Amateria default constructor called" << std::endl;
}

Amateria::Amateria(const Amateria& _ref)
{
    type = _ref.type;
	std::cout << "Amateria copy constructor called" << std::endl;
}

Amateria::~Amateria()
{
	std::cout << "Amateria " << " has destroyed" << std::endl;
}

Amateria& Amateria::operator=(const Amateria& ref)
{
	std::cout << "Amateria assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}
