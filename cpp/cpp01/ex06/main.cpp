#include <iostream>
#include <cctype>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    Harl a;
    a.complain(argv[1]);
    return (0);
}
