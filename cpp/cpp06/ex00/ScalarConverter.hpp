#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &ScalarConverter);
    ScalarConverter &operator=(const ScalarConverter& ScalarConverter);
public:
    static void convert(std::string data);

    ~ScalarConverter( void );
};
