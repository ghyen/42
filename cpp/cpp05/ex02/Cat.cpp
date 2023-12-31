#include "Cat.hpp"

std::string Cat::getBrain(unsigned int idx)
{
	return brain->getIdeas(idx);
}

void Cat::setBrain(unsigned int idx, std::string str)
{
	brain->setIdeas(idx, str);
}

Cat::Cat() : Animal()
{
	brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& _ref)
{
	this->type = _ref.type;
	brain = new Brain(*_ref.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat " << " has destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Cat assignment operator called" << std::endl;
	delete brain;
	brain = new Brain(*ref.brain);
	type = ref.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "냐옹" << std::endl;
}
