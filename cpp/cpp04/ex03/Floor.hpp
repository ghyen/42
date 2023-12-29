# pragma once

#include "Amateria.hpp"
#include "ICharacter.hpp"

class Floor : public AMateria {
private:
    static void *trashBin[100];
public:
    void takeTrash(void *trash);

    Floor();
    Floor(const Floor &Floor);
    Floor &operator=(const Floor& Floor);
    ~Floor( void );
};
