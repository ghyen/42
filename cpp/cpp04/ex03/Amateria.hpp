# ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class Amateria {
protected:

public:
    std::string const &getType( void ) const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    Amateria(std::string const & type);
    Amateria();
    Amateria(const Amateria &Amateria);
    Amateria &operator=(const Amateria& Amateria);
    virtual ~Amateria( void );
};

#endif
