#include "MateriaSource.hpp"

MateriaSource::~IMateriaSource()
{

}

void learnMateria(AMateria*)
{
	
}

AMateria* createMateria(std::string const & type)
{
	
}

MateriaSource::MateriaSource() : IMateriaSource()
{
	this->type = "MateriaSource";
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& _ref)
{
	this->type = _ref.type;
	brain = new Brain(*_ref.brain);
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	delete brain;
	std::cout << "MateriaSource " << " has destroyed" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	delete brain;
	brain = new Brain(*ref.brain);
	type = ref.type;
	return *this;
}

void MateriaSource::makeSound(void) const
{
	std::cout << "냐옹" << std::endl;
}
