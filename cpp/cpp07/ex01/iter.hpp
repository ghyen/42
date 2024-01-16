#pragma once
#include <cstddef>
#include <iostream>

template <typename T1, typename T2>

void iter(T1 *add, size_t len, T2 f)
{
    for (size_t i = 0; i < len; i++)
        f(add[i]);
}

template <typename T>
void print(T a)
{
	std::cout << a << ' ';
}
