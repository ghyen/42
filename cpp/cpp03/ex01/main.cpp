#include <iostream>
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap gkwon = ScavTrap("gkwon");
    ScavTrap gkwon = ScavTrap("gkwon");
    std::cout << "HP is " << gkwon.getHitPoints() << std::endl;
    std::cout << "Energy points is " << gkwon.getEnergyPoints() << std::endl;
    std::cout << "Attack damage is " << gkwon.getAttackDamage() << std::endl;
    gkwon.attack("evaluater");
    gkwon.takeDamage(5);
    std::cout << "HP is " << gkwon.getHitPoints() << std::endl;
    return (0);
}
