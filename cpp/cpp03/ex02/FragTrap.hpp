#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:

public:
    void highFivesGuys(void);
    
    FragTrap();
    FragTrap(const FragTrap &FragTrap);
    FragTrap(const std::string _name);
    FragTrap &operator=(const FragTrap& FragTrap);
    ~FragTrap( void );
};
