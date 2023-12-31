#include "Bureaucrat.hpp"

std::string Bureaucrat::getName( void ) const
{
    return name;
}

Bureaucrat::Bureaucrat() : name("default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& _ref)
{
    type = _ref.type;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << " has destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	type = ref.type;
	return *this;
}

void &operator<<(std::ostream &out, const Bureaucrat &ref)
{
	std::cout << ref->getName() << ",  bureaucrat grade " << ref->getGrade() << "." << std::endl;
}