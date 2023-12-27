#include "Brain.hpp"

std::string Brain::getIdeas(unsigned int idx)
{
	return ideas[idx];
}

void Brain::setIdeas(unsigned int idx, std::string str)
{
	ideas[idx] = str;
}

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& _ref)
{
	for (unsigned long i = 0; i < ideas->length(); i++)
		ideas[i] = _ref.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain " << " has destroyed" << std::endl;
}

Brain& Brain::operator=(const Brain& ref)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (unsigned long i = 0; i < ideas->length(); i++)
		ideas[i] = ref.ideas[i];
	return *this;
}
