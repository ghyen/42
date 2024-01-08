#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
  		throw AForm::NotSignedException();
  	if (executor.getGrade() > execStandard)
  		throw AForm::GradeTooLowException();
	std::cout << "drilling~~" << std::endl;
	srand(time(NULL));
	if (rand() % 10 < 5)
		std::cout << executor.getName() << ": successfully robotomized" << std::endl;
	else
		std::cout << executor.getName() << ": robotomize failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 150, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 150, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref.getName(), ref.getGrade(), 72, 45) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	ref.getGrade();
	throw CanNotCopyException();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}
