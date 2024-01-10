#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string targetForm)
{
	int idx = -1;
	const std::string type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
		if (type[i] == formName)
			idx = i;
	switch (idx)
	{
	case -1:
		throw NotExistException();
	std::cout << "Intern creates " << targetForm << std::endl;
	case 0:
		return new ShrubberyCreatiohnForm(targetForm);
	case 1:
		return new RobotomyRequestForm(targetForm);
	case 2:
		return new PresidentialPardonForm(targetForm);
	}
	return NULL;
}

const char* Intern::NotExistException::what() const throw()
{
	return "not exist that kind of form";
}
