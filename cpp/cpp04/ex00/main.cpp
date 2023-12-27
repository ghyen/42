#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();


    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* j1 = new WrongDog();
    const WrongAnimal* i1 = new WrongCat();
    std::cout << j1->getType() << " " << std::endl;
    std::cout << i1->getType() << " " << std::endl;
    i1->makeSound(); //will output the cat sound!
    j1->makeSound();
    meta1->makeSound();
    delete meta;
    delete meta1;
    delete i;
    delete i1;
    delete j;
    delete j1;
    return 0;
}
