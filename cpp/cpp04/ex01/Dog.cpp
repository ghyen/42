#include "Dog.hpp"

std::string Dog::getBrain(unsigned int idx)
{
	return brain->getIdeas(idx);
}

void Dog::setBrain(unsigned int idx, std::string str)
{
	brain->setIdeas(idx, str);
}

Dog::Dog() : Animal()
{
	brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& _ref)
{
	this->type = _ref.type;
	brain = _ref.brain;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog " << " has destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Dog assignment operator called" << std::endl;
	brain = ref.brain;
	type = ref.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "멍멍" << std::endl;
}
