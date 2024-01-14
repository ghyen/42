#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>

class ScalarConverter {
private:
    ScalarConverter(const ScalarConverter &ScalarConverter);
    ScalarConverter &operator=(const ScalarConverter& ScalarConverter);
public:
    static void convert(std::string data);

    ScalarConverter();
    virtual ~ScalarConverter( void );

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };

    class CanNotCopyException : public std::exception
    {
        const char* what() const throw();
    };
};
