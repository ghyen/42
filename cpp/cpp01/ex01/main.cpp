#include <iostream>
#include <cctype>
#include "Zombie.hpp"

int main( void )
{
    int num = 10;
    std::string name = "gkwon";
    Zombie *group = zombieHorde(num, name);
    for (int i = 0; i < num; i++)
        group[i].announce();

    delete[] group;
    return (0);
}
