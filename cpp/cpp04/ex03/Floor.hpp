# pragma once
#include <iostream>
class Floor {
private:
    static void *trashBin[100];
public:
    void takeTrash(void *trash);

    Floor();
    Floor(const Floor &Floor);
    Floor &operator=(const Floor& Floor);
    ~Floor( void );
};
