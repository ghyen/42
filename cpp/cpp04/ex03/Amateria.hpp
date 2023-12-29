#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    std::string const &getType( void ) const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    AMateria(std::string const & type);
    AMateria();
    AMateria(const AMateria &AMateria);
    AMateria &operator=(const AMateria& AMateria);
    virtual ~AMateria( void );
};
