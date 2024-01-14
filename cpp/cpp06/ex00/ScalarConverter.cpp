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


static void print_char(const double data)
{
    const char val = static_cast<char>(data);
    if (std::isnan(data) || data < std::numeric_limits<char>::min() || data > std::numeric_limits<char>::max())
        std::cerr << "char: impossible" << std::endl;
    else if (!std::isprint(val))
        std::cerr << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << val << std::endl;
}

static void print_int(const double data)
{
    const int val = static_cast<int>(data);
    if (std::isnan(data) || data < std::numeric_limits<int>::min() || data > std::numeric_limits<int>::max())
        std::cerr << "int: impossible" << std::endl;
    else
        std::cout << "int: " << val << std::endl;
}

static void print_float(const double data)
{
    const float val = static_cast<float>(data);
    if (std::isnan(data) || data < std::numeric_limits<float>::lowest() || data > std::numeric_limits<float>::max())
        std::cerr << "float: impossible" << std::endl;
    else
        std::cout << "float: " << val << "f" << std::endl;
}

static void print_double(const double data)
{
    if (std::isnan(data) || data < std::numeric_limits<double>::lowest() || data > std::numeric_limits<double>::max())
        std::cerr << "double: impossible" << std::endl;
    else
        std::cout << "double: " << data << std::endl;
}

void ScalarConverter::convert(std::string data)
{
    double tmp;

    if (data.length() == 1 && std::isalpha(data[0]))
		tmp = static_cast<double>(data[0]);
	else
		tmp = std::strtod(data.c_str(), NULL);

    std::string::size_type idx = data.find('.');
    if (idx == std::string::npos || idx == data.length() - 1)
        std::cout << std::fixed << std::setprecision(1) << data << std::endl;
    else
    {
        idx = data.length() - idx - 1;
        if (data[data.length()- 1] == 'f')
            idx--;
        std::cout << std::fixed << std::setprecision(idx) << data << std::endl;
    }
    print_char(tmp);
    print_int(tmp);
    print_float(tmp);
    print_double(tmp);
}
