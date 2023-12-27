# ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
    Brain *brain;
public:
    void makeSound(void) const;
    virtual std::string getBrain(unsigned int idx);
    virtual void setBrain(unsigned int idx, std::string str);

    Dog();
    Dog(const Dog &Dog);
    Dog &operator=(const Dog& Dog);
    ~Dog( void );
};

#endif
