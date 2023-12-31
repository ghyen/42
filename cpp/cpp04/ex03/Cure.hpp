# pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
private:

public:
    void use(ICharacter& target);
    AMateria* clone() const;

    Cure();
    Cure(const Cure &Cure);
    Cure &operator=(const Cure& Cure);
    ~Cure( void );
};
