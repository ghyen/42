# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon(std::string _type);
    ~Weapon();
    std::string const &getType(void) const;
    void setType(const std::string _type);
};

#endif
