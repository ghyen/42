#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap {
private:

public:
    void guardGate();
    void attack();
    
    ScavTrap();
    ScavTrap(const ScavTrap &ScavTrap);
    ScavTrap(const std::string _name);
    ScavTrap &operator=(const ScavTrap& ScavTrap);
    ~ScavTrap( void );
};
