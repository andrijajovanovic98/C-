#ifndef CLAPPTRAPP_HPP
#define CLAPPTRAPP_HPP

#include <iostream>

class ClapTrap {
private:

    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:

    ClapTrap(void);
    ~ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);

  
    ClapTrap(std::string name);
    void attack(const std::string& target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);

};

#endif
