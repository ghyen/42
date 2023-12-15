#include "Zombie.hpp"
#include <sstream>

static std::string castingString( int input )
{
    std::stringstream ret;
    
    ret << input;
    return (ret.str());
}

Zombie* zombieHorde( int N, std::string name)
{
    Zombie *ZombiesAddress = new Zombie[N];

    for (int i = 0; i < N; i++)
        ZombiesAddress[i].setName(name + castingString(i));
    return (ZombiesAddress);
}
