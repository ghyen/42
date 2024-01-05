#include "AForm.hpp"

std::string AForm::getName( void ) const
{
    return name;
}

int AForm::getGrade( void ) const
{
	return grade;
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
	if (bureaucrat.getGrade() > getGrade())
		throw GradeTooLowException();
	sign = true;
}

AForm::AForm() : name(""), grade(150), sign(false){}

AForm::AForm(std::string _name, int _grade) : name(_name), grade(_grade), sign(false){}

AForm::AForm(const AForm& _ref) : name(_ref.name), grade(_ref.grade), sign(_ref.sign)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

AForm::~AForm(){}

AForm& AForm::operator=(const AForm& ref)
{
	std::string(ref.name);
	throw CanNotCopyException();
	return *this;
}

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

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
	os << ref.getName() << ", form grade " << ref.getGrade() << "and signed is " << ref.getSigned();
	return os;
}
