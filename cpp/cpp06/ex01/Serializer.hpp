#pragma once
#include <iostream>

struct Data {
    const static unsigned int gwkon = 1;
};

class Serializer {
private:
    Serializer();
    Serializer(const Serializer &Serializer);
    Serializer &operator=(const Serializer& Serializer);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

    ~Serializer( void );
};
