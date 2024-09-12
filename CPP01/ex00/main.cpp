#include "Zombie.hpp"
#include <iostream>


int main(void)
{
    Zombie *zombie = newZombie("Dexter");
    zombie->announce();
    Zombie Zombie("Andrija");

    Zombie.announce();
    
    randomChump("Valaki");

    delete(zombie);

    return (0);
}