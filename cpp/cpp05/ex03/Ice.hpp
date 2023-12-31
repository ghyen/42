# pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
private:

public:
    void use(ICharacter& target);
    AMateria* clone() const;

    Ice();
    Ice(const Ice &Ice);
    Ice &operator=(const Ice& Ice);
    ~Ice( void );
};
