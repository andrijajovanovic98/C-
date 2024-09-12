#include "Zombie.hpp"

void Zombie::setName(std::string setName)
{
    this->name = setName;
}

Zombie::Zombie()
{
    std::cout << "Zombie" << " is boorn" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << " is ready" << std::endl;
}