#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

static void print_char(const double data)
{
    const char val = static_cast<char>(data);
    if (data != data || data < std::numeric_limits<char>::min() || data > std::numeric_limits<char>::max())
        std::cerr << "char: impossible" << std::endl;
    else if (!std::isprint(val))
        std::cerr << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << val << "'" << std::endl;
}

static void print_int(const double data)
{
    const int val = static_cast<int>(data);
    if (data != data || data < std::numeric_limits<int>::min() || data > std::numeric_limits<int>::max())
        std::cerr << "int: impossible" << std::endl;
    else
        std::cout << "int: " << val << std::endl;
}

static void print_float(const double data)
{
    const float val = static_cast<float>(data);
    if (data != data)
        std::cerr << "float: nanf" << std::endl;
    else if (val == std::numeric_limits<float>::infinity())
        std::cerr << "float: +inf" << std::endl;
    else if (val == -std::numeric_limits<float>::infinity())
        std::cerr << "float: -inf" << std::endl;
    else if (std::isnan(data) || data < -std::numeric_limits<float>::max() || data > std::numeric_limits<float>::max())
        std::cerr << "float: impossible" << std::endl;
    else
        std::cout << "float: " << val << "f" << std::endl;
}

static void print_double(const double data)
{
    if (data != data)
        std::cerr << "double: nan" << std::endl;
    else if (data == std::numeric_limits<float>::infinity())
        std::cerr << "double: +inf" << std::endl;
    else if (data == -std::numeric_limits<float>::infinity())
        std::cerr << "double: -inf" << std::endl;
    else if (std::isnan(data) || data < -std::numeric_limits<double>::max() || data > std::numeric_limits<double>::max())
        std::cerr << "double: impossible" << std::endl;
    else
        std::cout << "double: " << data << std::endl;
}

void ScalarConverter::convert(std::string data)
{
    double tmp;

    std::cout << std::fixed << std::setprecision(1);
    if (data.length() == 1 && !std::isdigit(data[0]))
		tmp = static_cast<double>(data[0]);
	else
        tmp = std::strtod(data.c_str(), NULL);
    if (data.length() >= 2)
        if ((!tmp && data[data.length() - 2] != '0' && "0.f" != data) || ".f" == data)
            return ;
    std::string::size_type idx = data.find('.');
    if (data.find_last_of('.') != idx)
        return ;
    if (idx != std::string::npos && idx != data.length() - 1)
    {
        idx = data.length() - idx - 1;
        if (data[data.length()- 1] == 'f')
            idx--;
        std::cout << std::fixed << std::setprecision(idx);
    }
    print_char(tmp);
    print_int(tmp);
    print_float(tmp);
    print_double(tmp);
}
