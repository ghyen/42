#pragma once

#include <iostream>

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	void setAttackDamage(unsigned int newAttackDamage);
    
    ClapTrap();
    ClapTrap(const ClapTrap &clapTrap);
    ClapTrap(const std::string _name);
    ClapTrap(const std::string _name, const unsigned int hitPoints, const unsigned int energyPoints, const unsigned int attackDamage);
    ClapTrap &operator=(const ClapTrap& clapTrap);
    ~ClapTrap( void );
};
