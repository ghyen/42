#pragma once
#include <iostream>
template <typename T>

void swap(T n1, T n2)
{
    T tmp = n1;
    n1 = n2;
    n2 = tmp;
}

template <typename T>
T min(T n1, T n2)
{
    return n1 >= n2 ? n2 : n1;
}

template <typename T>
T max(T n1, T n2)
{
    return n1 <= n2 ? n2 : n1;
}

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &ScalarConverter);
    ScalarConverter &operator=(const ScalarConverter& ScalarConverter);
public:
    static void convert(std::string data);

    ~ScalarConverter( void );
};
