#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:

public:
    void guardGate();
    void attack(const std::string& target);
    
    ScavTrap();
    ScavTrap(const ScavTrap &ScavTrap);
    ScavTrap(const std::string _name);
    ScavTrap &operator=(const ScavTrap& ScavTrap);
    ~ScavTrap( void );
};
