#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie( const std::string _name ) : name(_name)
{
    std::cout << "zombie " + Zombie::getName() + " is initialized\n";
}

Zombie::~Zombie( void )
{
    std::cout << Zombie::getName() + " is dead.\n";
}

void Zombie::announce( void )
{
    std::cout << Zombie::getName() + ": BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::getName( void ) const
{
    return (this->name);
}

void Zombie::setName(const std::string _name )
{
    this->name = _name;
}