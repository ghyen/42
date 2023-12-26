# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
private:

public:
    void makeSound(void) const;

    Cat();
    Cat(const Cat &Cat);
    Cat &operator=(const Cat& Cat);
    ~Cat( void );
};

#endif
