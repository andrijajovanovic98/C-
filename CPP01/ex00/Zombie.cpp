#include "Zombie.hpp"


void Zombie::setname(std::string nameToSet)
{
    name = nameToSet;
}


void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(const std::string &setName)
{
    std::cout << setName << " is boorn" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is destroyd" << std::endl;
}
