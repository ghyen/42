# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
private:

public:
    void makeSound(void) const;

    WrongCat();
    WrongCat(const WrongCat &WrongCat);
    WrongCat &operator=(const WrongCat& WrongCat);
    ~WrongCat( void );
};

#endif
