# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    std::string getName(void) const;
    void setName(const std::string _name);
    Zombie();
    Zombie(const std::string _name);
    ~Zombie( void );
    void announce( void );
};

Zombie *newZombie(std::string _name);
Zombie *newZombie(void);
Zombie *zombieHorde(int N, std::string name);

#endif
