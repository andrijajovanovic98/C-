#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"


class HumanB {
private:

    Weapon *weapon;
    std::string name;


public:

    HumanB(std::string name);
    void setWeapon(class Weapon& newWeapon);
    void attack();

};

#endif