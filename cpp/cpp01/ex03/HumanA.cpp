#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : name(_name), weapon(_weapon) {}

HumanA::~HumanA() {}

void HumanA::setWeapon(Weapon &_weapon)
{
    this->weapon = _weapon;
}

void HumanA::attack(void)
{
    std::cout << name + " attacks with their " + weapon.getType() + "\n";

}
