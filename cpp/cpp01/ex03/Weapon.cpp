# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type) {}

Weapon::~Weapon() {}

std::string const &Weapon::getType(void) const
{
    return(type);
}

void Weapon::setType(const std::string _type)
{
    type = _type;
}

#endif