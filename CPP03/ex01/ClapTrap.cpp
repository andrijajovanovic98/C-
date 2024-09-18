#include "ClapTrap.hpp"

// Orthodox Canon Form

ClapTrap::ClapTrap(void)
{
    this->name = "Unknown";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "ClapTrap " << this->name << " has been copid!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << this->name << " has been assigned!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap is destroyed from destructor" << std::endl;
}

// Parameterized constructor && destructor and member functions

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap is created" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \
        << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "Claptrap has no energyPoints!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amout)
{
    if (hitPoints > 0)
    {
        this->hitPoints -= amout;
        std::cout << "Someone attacked " << this->name;
        std::cout << " with " << amout << " damage points";
        std::cout << std::endl;
    }
    else
        std::cout << this->name << " is already dead" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amout)
{
    if (this->energyPoints > 0)
    {
        this->hitPoints += amout;
        this->energyPoints -= amout;
        std::cout << "ClapTrap" << name << " got " << amout << " hitPoints";
        std::cout << std::endl;
    }
    else
        std::cout << "ClapTrap has no energyPoints to headl itself!" << std::endl;
}

