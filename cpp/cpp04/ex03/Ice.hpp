# pragma once

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
private:

public:
    virtual void use(ICharacter& target);

    Ice();
    Ice(const Ice &Ice);
    Ice &operator=(const Ice& Ice);
    ~Ice( void );
};
