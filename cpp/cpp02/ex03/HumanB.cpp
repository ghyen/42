#include "HumanB.hpp"

HumanB::HumanB(std::string _name, Weapon *_weapon) : name(_name), weapon(_weapon) {}

HumanB::HumanB(std::string _name) : name(_name)
{
    weapon = NULL;
}

HumanB::HumanB(void) : name("")
{
    weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &_weapon)
{
    this->weapon = &_weapon;
}

void HumanB::attack(void)
{
    std::cout << name + " attacks with their " + (*weapon).getType() + "\n";
}