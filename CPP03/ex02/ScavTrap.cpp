#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->name = "Unknown";
    std::cout << "ScavTrap " << this->name << " (son of ClapTrap) is going to help for ClapTrap" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << this->name << " (son of ClapTrap) is going to help for ClapTrap" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

void ScavTrap::guardGate()
{
    std::cout << "SvacTrap is now in Gate keeper mode !" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
     std::cout << "ScavTrap is dead" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " \
        << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "Scavtrap has no energyPoints!" << std::endl;
}

