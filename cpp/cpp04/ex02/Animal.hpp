# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;

public:
    std::string getType( void ) const;
    virtual void makeSound(void) const = 0;

    Animal();
    Animal(const Animal &Animal);
    Animal &operator=(const Animal& Animal);
    virtual ~Animal( void );
};

#endif
