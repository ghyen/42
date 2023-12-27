#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* j = new Dog();
    Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << j->setBrain(0, "hi") << std::endl;
    
    delete j;
    delete i;
    
    return 0;
}
