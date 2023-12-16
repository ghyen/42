# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    std::string getName( void ) const;
    Zombie(const std::string _name );
    ~Zombie( void );
    void announce( void );
};

Zombie *newZombie(std::string _name);
void randomChump(std::string _name);

#endif
