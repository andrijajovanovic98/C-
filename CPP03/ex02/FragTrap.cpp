#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
     std::cout << "FragTrap " << this->name << " (the scound son of ClapTrap) is going to help for ClapTrap" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap()
{
    this->name = "Unknown";
    std::cout << "FragTrap " << this->name << " (the scound son of ClapTrap) is going to help for ClapTrap" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap is dead" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Hight five, guys!" << std::endl;
}
