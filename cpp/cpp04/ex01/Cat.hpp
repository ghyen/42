# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
private:
    Brain *brain;
public:
    void makeSound(void) const;
    virtual std::string getBrain(unsigned int idx);
    virtual void setBrain(unsigned int idx, std::string str);

    Cat();
    Cat(const Cat &Cat);
    Cat &operator=(const Cat& Cat);
    ~Cat( void );
};

#endif
