#include <iostream>
#include <cctype>
#include "Zombie.hpp"

int main( void )
{
    Zombie *zombie = newZombie("newZombie");
    zombie->announce();
    randomChump("randomZombie");
    delete zombie;

    return (0);
}