#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Dog *dog1 = new Dog();
    dog1->setBrain(0, "first idea");
    Dog *dog2 = new Dog(*dog1);
    dog2->setBrain(0, "second idea");
    std::cout << dog1->getBrain(0) << std::endl;
    std::cout << dog2->getBrain(0) << std::endl;

    return 0;
}
