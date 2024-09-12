#include "HumanB.hpp"


void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
    weapon = NULL;
    this->name = name;
}


void HumanB::setWeapon(class Weapon& newWeapon)
{
    this->weapon = &newWeapon;
}