#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
  		throw AForm::NotSignedException();
  	if (executor.getGrade() > execStandard)
  		throw AForm::GradeTooLowException();
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 150, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 150, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref.getName(), ref.getGrade(), 25, 5) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	throw CanNotCopyException();
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm( void ) {}