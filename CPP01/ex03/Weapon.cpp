#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string newtype)
{
    this->type = newtype;
    std::cout << this->type << std::endl;
}

Weapon::Weapon()
{
    return ;
}


Weapon::Weapon(std::string Weapon)
{
    this->type = Weapon;
}
