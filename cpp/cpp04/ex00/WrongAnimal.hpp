# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    std::string getType( void ) const;
    void makeSound(void) const;

    WrongAnimal();
    WrongAnimal(const WrongAnimal &WrongAnimal);
    WrongAnimal &operator=(const WrongAnimal& WrongAnimal);
    virtual ~WrongAnimal( void );
};

#endif
