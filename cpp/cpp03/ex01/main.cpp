#include <iostream>
#include <cctype>
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap gkwon = ScavTrap("gkwon");
    gkwon.attack("evaluater");
    gkwon.setAttackDamage(2);
    gkwon.attack("evaluater");
    std::cout << "HP is " << gkwon.getHitPoints() << std::endl;
    gkwon.takeDamage(5);
        std::cout << "HP is " << gkwon.getHitPoints() << std::endl;
    return (0);
}
