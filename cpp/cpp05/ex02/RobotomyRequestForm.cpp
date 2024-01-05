#include "Form.hpp"

std::string Form::getName( void ) const
{
    return name;
}

int Form::getGrade( void ) const
{
	return grade;
}

bool Form::getSigned( void ) const
{
	if (sign)
		return true;
	else
		return false;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (sign)
		throw alreadySignedException();
	if (bureaucrat.getGrade() > getGrade())
		throw GradeTooLowException();
	sign = true;
}

Form::Form() : name(""), grade(150), sign(false){}

Form::Form(std::string _name, int _grade) : name(_name), grade(_grade), sign(false){}

Form::Form(const Form& _ref) : name(_ref.name), grade(_ref.grade), sign(_ref.sign)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Form::~Form(){}

Form& Form::operator=(const Form& ref)
{
	std::string(ref.name);
	throw CanNotCopyException();
	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::CanNotCopyException::what() const throw()
{
	return "Can not copy";
}

const char *Form::alreadySignedException::what() const throw()
{
	return "already signed";
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
	os << ref.getName() << ", form grade " << ref.getGrade() << "and signed is " << ref.getSigned();
	return os;
}
