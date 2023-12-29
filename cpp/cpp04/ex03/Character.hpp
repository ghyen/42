# pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria *inventory[4];
    Floor floor;

public:
    Character();
    Character(std::string &_name);
    Character(const Character &Character);
    Character &operator=(const Character& Character);
    ~Character( void ) override;

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
