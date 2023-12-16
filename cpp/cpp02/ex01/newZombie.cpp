#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string _name )
{
    Zombie *newZombie = new Zombie(_name);
    return (newZombie);
}

Zombie* newZombie( void )
{
    Zombie *newZombie = new Zombie("default");
    return (newZombie);
}