#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->type = "cure";
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& _ref)
{
	this->type = _ref.type;
	//std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure " << " has destroyed" << std::endl;
}

Cure& Cure::operator=(const Cure& ref)
{
	//std::cout << "Cure assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure();
}
