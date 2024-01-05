#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Form form;

std::string Bureaucrat::getName( void ) const
{
    return name;
}

int Bureaucrat::getGrade( void ) const
{
	return grade;
}

Bureaucrat::Bureaucrat() : name(""), grade(150){}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade){}

Bureaucrat::Bureaucrat(const Bureaucrat& _ref) : name(_ref.name), grade(_ref.grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::string(ref.name);
	throw CanNotCopyException();
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Bureaucrat::CanNotCopyException::what() const throw()
{
	return "Can not copy";
}

void Bureaucrat::increseGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decreseGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return os;
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << getName() << " couldn’t sign " << form.getGrade() << " because " << e.what() << ".\n";
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	form->excute();
}
