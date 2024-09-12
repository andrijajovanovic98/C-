#include "Zombie.hpp"

Zombie* newZombie(const std::string &name)
{
    Zombie *newZombie = new Zombie(name);

    newZombie->setname(name);
    return (newZombie);
}