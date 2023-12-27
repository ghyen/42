#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* j = new Dog();
    Animal* i = new Cat();

    const unsigned int loop = 10;
    Animal *Animals[loop];
    unsigned int idx = 0;

    while (idx < loop)
    {
        if (idx < 5)
            Animals[idx] = new Dog();
        else
            Animals[idx] = new Cat();
        
        idx++;
    }
    idx = 0;
    while (idx < loop)
    {
        Animals[idx]->makeSound();
        idx++;
    }

    idx = 0;
    while (idx < loop)
    {
        delete Animals[idx];
        idx++;
    }
     
    delete j;
    delete i;
    
    return 0;
}
