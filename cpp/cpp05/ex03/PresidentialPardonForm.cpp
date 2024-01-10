#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
  		throw AForm::NotSignedException();
  	if (executor.getGrade() > execStandard)
  		throw AForm::GradeTooLowException();
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref.getName(), 25, 5) {}
PresidentialPardonForm::~PresidentialPardonForm( void ) {}
