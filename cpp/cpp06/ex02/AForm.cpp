#include "AForm.hpp"
#include "Bureaucrat.hpp"

const std::string AForm::getName( void ) const
{
    return name;
}

int AForm::getsignStandard( void ) const
{
	return signStandard;
}

int AForm::getexecStandard( void ) const
{
	return execStandard;
}

bool AForm::getSigned( void ) const
{
	if (sign)
		return true;
	else
		return false;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (sign)
		throw alreadySignedException();
	if (bureaucrat.getGrade() > getsignStandard())
		throw GradeTooLowException();
	sign = true;
}

AForm::AForm() : name("default"), sign(false), signStandard(150), execStandard(150) {}

AForm::AForm(std::string _name, const int _signStandard, const int _execStandard) 
: name(_name), sign(false), signStandard(_signStandard), execStandard(_execStandard){}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::CanNotCopyException::what() const throw()
{
	return "Can not copy";
}

const char *AForm::alreadySignedException::what() const throw()
{
	return "already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "you have to sign first";
}

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
	os << ref.getName() << ", form sign standard " << ref.getsignStandard() << "and signed is " << ref.getSigned();
	return os;
}
