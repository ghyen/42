#include "AMateria.hpp"
#include "ICharacter.hpp"

std::string const &AMateria::getType( void ) const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << type << " to " << target.getName() << " *" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria() : type("default")
{
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& _ref) : type(_ref.type)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria " << " has destroyed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& ref)
{
	//std::cout << "AMateria assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}
