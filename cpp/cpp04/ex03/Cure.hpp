# pragma once

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
private:

public:
    virtual void use(ICharacter& target);

    Cure();
    Cure(const Cure &Cure);
    Cure &operator=(const Cure& Cure);
    ~Cure( void );
};
