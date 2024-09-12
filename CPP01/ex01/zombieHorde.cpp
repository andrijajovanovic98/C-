#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    
    Zombie  *horde = new Zombie[N];

    while (i < N)
    {
        std::stringstream ss;

        ss << name << "_" << (i + 1);
        horde[i].setName(ss.str());
        i++;
    }
    return (horde);
}
