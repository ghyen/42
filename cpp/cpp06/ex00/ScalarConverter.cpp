#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

const char* ScalarConverter::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *ScalarConverter::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *ScalarConverter::CanNotCopyException::what() const throw()
{
	return "Can not copy";
}

void ScalarConverter::convert(std::string data)
{
	istringstream iss(data);
}
