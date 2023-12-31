#include "Brain.hpp"

std::string Brain::getIdeas(int idx)
{
	if (idx < 100 && idx >= 0)
		return ideas[idx];
	return "";
}

void Brain::setIdeas(int idx, std::string str)
{
	if (idx < 100 && idx >= 0)
		ideas[idx] = str;
}

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
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
