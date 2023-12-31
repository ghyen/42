# pragma once
#include <iostream>
#include "AMateria.hpp"

class Floor {
private:
    AMateria *trashBin[100];
public:
    void takeTrash(AMateria *trash);

    Floor();
    Floor(const Floor &Floor);
    Floor &operator=(const Floor& Floor);
    ~Floor( void );
};
