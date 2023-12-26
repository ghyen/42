# ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
private:

public:
    void makeSound(void) const;

    Dog();
    Dog(const Dog &Dog);
    Dog &operator=(const Dog& Dog);
    ~Dog( void );
};

#endif
