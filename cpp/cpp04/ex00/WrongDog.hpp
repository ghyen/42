# ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongDog : public WrongAnimal {
private:

public:
    void makeSound(void) const;

    WrongDog();
    WrongDog(const WrongDog &WrongDog);
    WrongDog &operator=(const WrongDog& WrongDog);
    ~WrongDog( void );
};

#endif
